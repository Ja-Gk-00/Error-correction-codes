import numpy as np
from numpy.typing import NDArray

from ecc.codes.base import ErrorCorrectionCode


class HammingCode(ErrorCorrectionCode):
    def __init__(self, r: int = 3, secded: bool = True) -> None:
        if r < 2:
            raise ValueError("r must be >= 2")
        self.r = r
        self.secded = secded
        self.n = (1 << r) - 1
        self.k = self.n - r
        self._total_n = self.n + (1 if secded else 0)

        self._H = self._build_parity_check_matrix()
        self._G = self._build_generator_matrix()

    @property
    def name(self) -> str:
        tag = "SECDED" if self.secded else "SEC"
        return f"Hamming({self._total_n},{self.k}) [{tag}]"

    @property
    def code_rate(self) -> float:
        return self.k / self._total_n

    @property
    def redundancy_ratio(self) -> float:
        return (self._total_n - self.k) / self.k

    @property
    def error_correction_capability(self) -> str:
        if self.secded:
            return "corrects 1-bit errors, detects 2-bit errors per block"
        return "corrects 1-bit errors per block"

    def encode(self, data: NDArray[np.uint8]) -> NDArray[np.uint8]:
        data = self._pad_to_multiple(data, self.k)
        blocks = data.reshape(-1, self.k)
        encoded_blocks = []
        for block in blocks:
            codeword = (block @ self._G) % 2
            if self.secded:
                parity = int(np.sum(codeword)) % 2
                codeword = np.append(codeword, parity)
            encoded_blocks.append(codeword.astype(np.uint8))
        return np.concatenate(encoded_blocks)

    def decode(self, data: NDArray[np.uint8]) -> NDArray[np.uint8]:
        data = self._pad_to_multiple(data, self._total_n)
        blocks = data.reshape(-1, self._total_n)
        decoded_blocks = []
        for block in blocks:
            if self.secded:
                overall_parity = int(np.sum(block)) % 2
                inner = block[: self.n].copy()
            else:
                inner = block.copy()

            syndrome = (self._H @ inner) % 2
            syndrome_val = 0
            for i, bit in enumerate(syndrome):
                syndrome_val |= int(bit) << (self.r - 1 - i)

            if syndrome_val != 0:
                if self.secded and overall_parity == 0:
                    pass
                else:
                    error_pos = syndrome_val - 1
                    if error_pos < self.n:
                        inner[error_pos] ^= 1

            data_bits = self._extract_data_bits(inner)
            decoded_blocks.append(data_bits)

        return np.concatenate(decoded_blocks)

    def _build_parity_check_matrix(self) -> NDArray[np.uint8]:
        cols = []
        for i in range(1, self.n + 1):
            col = [(i >> (self.r - 1 - j)) & 1 for j in range(self.r)]
            cols.append(col)
        return np.array(cols, dtype=np.uint8).T

    def _build_generator_matrix(self) -> NDArray[np.uint8]:
        data_positions = [i for i in range(self.n) if not self._is_power_of_two(i + 1)]
        parity_positions = [i for i in range(self.n) if self._is_power_of_two(i + 1)]

        gen = np.zeros((self.k, self.n), dtype=np.uint8)
        for row_idx, col in enumerate(data_positions):
            gen[row_idx, col] = 1

        for p_idx, p_col in enumerate(parity_positions):
            bit_mask = p_col + 1
            for d_idx, d_col in enumerate(data_positions):
                if ((d_col + 1) & bit_mask) != 0:
                    gen[d_idx, p_col] = 1

        return gen

    def _extract_data_bits(self, codeword: NDArray[np.uint8]) -> NDArray[np.uint8]:
        data_positions = [i for i in range(self.n) if not self._is_power_of_two(i + 1)]
        return codeword[data_positions]

    @staticmethod
    def _is_power_of_two(x: int) -> bool:
        return x > 0 and (x & (x - 1)) == 0
