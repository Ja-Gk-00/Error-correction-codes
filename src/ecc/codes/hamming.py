"""Hamming code -- single-error-correcting, double-error-detecting (SECDED).

Generalized Hamming(2^r - 1, 2^r - 1 - r) with an optional extra parity bit
for SECDED.  Default ``r=3`` gives the classic Hamming(7, 4) code.
"""

import numpy as np
from numpy.typing import NDArray

from ecc.codes.base import ErrorCorrectionCode


class HammingCode(ErrorCorrectionCode):
    """Generalized Hamming code.

    Parameters
    ----------
    r:
        Number of parity-check bits.  Produces codewords of length
        ``n = 2**r - 1`` with ``k = n - r`` data bits.  Default ``3``
        gives Hamming(7, 4).
    secded:
        When ``True`` (default) an extra overall-parity bit is appended,
        enabling *single-error correction, double-error detection* (SECDED).
    """

    def __init__(self, r: int = 3, secded: bool = True) -> None:
        if r < 2:
            raise ValueError("r must be >= 2")
        self.r = r
        self.secded = secded
        self.n = (1 << r) - 1  # codeword length (without SECDED bit)
        self.k = self.n - r  # data bits per block
        self._total_n = self.n + (1 if secded else 0)

        # Build parity-check matrix H (r x n)
        self._H = self._build_parity_check_matrix()
        # Build generator matrix G (k x n) in systematic form
        self._G = self._build_generator_matrix()

    # --- ErrorCorrectionCode interface ---

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
                    # Two-bit error detected — uncorrectable; pass through
                    pass
                else:
                    # Single-bit error — correct it
                    error_pos = syndrome_val - 1
                    if error_pos < self.n:
                        inner[error_pos] ^= 1

            # Extract data bits (systematic positions)
            data_bits = self._extract_data_bits(inner)
            decoded_blocks.append(data_bits)

        return np.concatenate(decoded_blocks)

    # --- Internal helpers ---

    def _build_parity_check_matrix(self) -> NDArray[np.uint8]:
        """Build the r x n parity-check matrix H.

        Columns are the binary representations of 1..n (big-endian).
        """
        cols = []
        for i in range(1, self.n + 1):
            col = [(i >> (self.r - 1 - j)) & 1 for j in range(self.r)]
            cols.append(col)
        return np.array(cols, dtype=np.uint8).T

    def _build_generator_matrix(self) -> NDArray[np.uint8]:
        """Build the systematic k x n generator matrix G.

        Data positions are all column indices whose 1-based index is *not*
        a power of two.  Parity positions are the powers of two.
        """
        data_positions = [i for i in range(self.n) if not self._is_power_of_two(i + 1)]
        parity_positions = [i for i in range(self.n) if self._is_power_of_two(i + 1)]

        gen = np.zeros((self.k, self.n), dtype=np.uint8)
        # Identity part at data positions
        for row_idx, col in enumerate(data_positions):
            gen[row_idx, col] = 1

        # Parity part: each parity bit covers positions where the
        # corresponding bit of the position index is 1.
        for p_idx, p_col in enumerate(parity_positions):
            bit_mask = p_col + 1  # 1-indexed position IS the power-of-2 mask
            for d_idx, d_col in enumerate(data_positions):
                if ((d_col + 1) & bit_mask) != 0:
                    gen[d_idx, p_col] = 1

        return gen

    def _extract_data_bits(self, codeword: NDArray[np.uint8]) -> NDArray[np.uint8]:
        """Extract the k data bits from a codeword (systematic positions)."""
        data_positions = [i for i in range(self.n) if not self._is_power_of_two(i + 1)]
        return codeword[data_positions]

    @staticmethod
    def _is_power_of_two(x: int) -> bool:
        return x > 0 and (x & (x - 1)) == 0
