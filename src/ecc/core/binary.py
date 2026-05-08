import numpy as np
from numpy.typing import NDArray


class BinaryConverter:
    @staticmethod
    def bytes_to_binary(data: bytes) -> NDArray[np.uint8]:
        arr = np.frombuffer(data, dtype=np.uint8)
        return np.unpackbits(arr).astype(np.uint8)

    @staticmethod
    def binary_to_bytes(bits: NDArray[np.uint8]) -> bytes:
        remainder = len(bits) % 8
        if remainder:
            bits = np.concatenate([bits, np.zeros(8 - remainder, dtype=np.uint8)])
        return np.packbits(bits.astype(np.uint8)).tobytes()

    @staticmethod
    def str_to_binary(text: str, encoding: str = "utf-8") -> NDArray[np.uint8]:
        return BinaryConverter.bytes_to_binary(text.encode(encoding))

    @staticmethod
    def binary_to_str(bits: NDArray[np.uint8], encoding: str = "utf-8") -> str:
        return BinaryConverter.binary_to_bytes(bits).decode(encoding, errors="replace")

    @staticmethod
    def int_to_binary(value: int, bit_width: int = 32) -> NDArray[np.uint8]:
        if value < 0:
            raise ValueError("Only non-negative integers are supported")
        bits = np.array(
            [(value >> (bit_width - 1 - i)) & 1 for i in range(bit_width)],
            dtype=np.uint8,
        )
        return bits

    @staticmethod
    def binary_to_int(bits: NDArray[np.uint8]) -> int:
        result = 0
        for b in bits:
            result = (result << 1) | int(b)
        return result

    @staticmethod
    def image_to_binary(
        image_array: NDArray[np.uint8],
    ) -> tuple[NDArray[np.uint8], tuple[int, ...]]:
        shape = image_array.shape
        flat = image_array.flatten()
        bits = np.unpackbits(flat).astype(np.uint8)
        return bits, shape

    @staticmethod
    def binary_to_image(bits: NDArray[np.uint8], shape: tuple[int, ...]) -> NDArray[np.uint8]:
        n_pixels = int(np.prod(shape))
        n_bits = n_pixels * 8
        if len(bits) < n_bits:
            bits = np.concatenate([bits, np.zeros(n_bits - len(bits), dtype=np.uint8)])
        else:
            bits = bits[:n_bits]
        flat = np.packbits(bits.astype(np.uint8))[:n_pixels]
        return flat.reshape(shape).astype(np.uint8)
