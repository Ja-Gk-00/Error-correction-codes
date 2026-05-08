import numpy as np
from numpy.typing import NDArray
from reedsolo import RSCodec

from ecc.codes.base import ErrorCorrectionCode


class ReedSolomonCode(ErrorCorrectionCode):
    def __init__(self, nsym: int = 10) -> None:
        if nsym < 1 or nsym > 254:
            raise ValueError("nsym must be in [1, 254]")
        self.nsym = nsym
        self._codec = RSCodec(nsym)
        self._n_symbols = 255
        self._k_symbols = 255 - nsym

    @property
    def name(self) -> str:
        return f"Reed-Solomon({self._n_symbols},{self._k_symbols})"

    @property
    def code_rate(self) -> float:
        return self._k_symbols / self._n_symbols

    @property
    def redundancy_ratio(self) -> float:
        return self.nsym / self._k_symbols

    @property
    def error_correction_capability(self) -> str:
        t = self.nsym // 2
        return f"corrects up to {t} symbol (byte) errors per {self._n_symbols}-byte block"

    def encode(self, data: NDArray[np.uint8]) -> NDArray[np.uint8]:
        byte_data = self._bits_to_bytes(data)
        encoded = self._codec.encode(byte_data)
        return self._bytes_to_bits(bytes(encoded))

    def decode(self, data: NDArray[np.uint8]) -> NDArray[np.uint8]:
        byte_data = self._bits_to_bytes(data)
        return self._decode_per_block(byte_data)

    def _decode_per_block(self, byte_data: bytes) -> NDArray[np.uint8]:
        block_size = self._n_symbols
        result = bytearray()
        for i in range(0, len(byte_data), block_size):
            block = byte_data[i : i + block_size]
            if len(block) <= self.nsym:
                result.extend(block)
                continue
            try:
                decoded = self._codec.decode(block)
                result.extend(bytes(decoded[0]))
            except Exception:
                data_len = len(block) - self.nsym
                result.extend(block[:data_len])
        return self._bytes_to_bits(bytes(result))

    @staticmethod
    def _bits_to_bytes(bits: NDArray[np.uint8]) -> bytes:
        remainder = len(bits) % 8
        if remainder:
            bits = np.concatenate([bits, np.zeros(8 - remainder, dtype=np.uint8)])
        return np.packbits(bits.astype(np.uint8)).tobytes()

    @staticmethod
    def _bytes_to_bits(data: bytes) -> NDArray[np.uint8]:
        arr = np.frombuffer(data, dtype=np.uint8)
        return np.unpackbits(arr).astype(np.uint8)

    def _strip_parity_bytes(self, byte_data: bytes) -> NDArray[np.uint8]:
        result = bytearray()
        block_size = self._n_symbols
        for i in range(0, len(byte_data), block_size):
            block = byte_data[i : i + block_size]
            data_len = min(len(block), block_size) - self.nsym
            if data_len > 0:
                result.extend(block[:data_len])
            else:
                result.extend(block)
        return self._bytes_to_bits(bytes(result))
