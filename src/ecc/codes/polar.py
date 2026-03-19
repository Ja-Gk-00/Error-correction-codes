"""Polar code -- channel-polarization-based error correction.

Implements a Polar(N, K) code with successive-cancellation (SC) decoding
and an SC-Flip decoder that retries with flipped least-reliable bits.
Frozen-bit positions are selected via Bhattacharyya-parameter estimation
for a Binary Symmetric Channel (BSC).
"""

from math import erfc, sqrt

import numpy as np
from numpy.typing import NDArray

from ecc.codes.base import ErrorCorrectionCode


class PolarCode(ErrorCorrectionCode):
    """Polar code with SC-Flip decoding.

    Parameters
    ----------
    n:
        Code length -- must be a power of 2.  Default ``256``.
    k:
        Number of information bits.  Must satisfy ``0 < k <= n``.
        Default ``128`` gives rate 1/2.
    design_snr_db:
        Design SNR (dB) used for frozen-bit selection via the
        Bhattacharyya parameter.  Default ``1.0``.
    channel_p:
        BSC crossover probability for LLR computation.  When ``None``,
        derived from *design_snr_db*.
    max_flips:
        Number of bit-flip attempts in the SC-Flip decoder.
        ``0`` disables flipping (plain SC).  Default ``8``.
    """

    def __init__(
        self,
        n: int = 256,
        k: int = 128,
        design_snr_db: float = 1.0,
        channel_p: float | None = None,
        max_flips: int = 8,
    ) -> None:
        if n < 2 or (n & (n - 1)) != 0:
            raise ValueError("n must be a power of 2")
        if not (0 < k <= n):
            raise ValueError("k must be in (0, n]")
        self._n = n
        self._k = k
        self.design_snr_db = design_snr_db
        self._max_flips = max_flips
        self._frozen_mask = self._compute_frozen_bits()
        self._info_indices = np.where(~self._frozen_mask)[0]
        self.set_channel_p(channel_p)

    # --- ErrorCorrectionCode interface ---

    @property
    def name(self) -> str:
        return f"Polar({self._n},{self._k})"

    @property
    def code_rate(self) -> float:
        return self._k / self._n

    @property
    def redundancy_ratio(self) -> float:
        return (self._n - self._k) / self._k

    @property
    def error_correction_capability(self) -> str:
        return (
            f"capacity-approaching at design SNR {self.design_snr_db} dB "
            f"(rate {self.code_rate:.2f})"
        )

    def set_channel_p(self, p: float | None) -> None:
        """Set the BSC crossover probability for LLR computation.

        If *p* is ``None``, a default is derived from *design_snr_db*
        using the BPSK/AWGN Q-function approximation.
        """
        if p is not None:
            p = float(np.clip(p, 1e-12, 1.0 - 1e-12))
            self._llr_magnitude = float(np.log((1.0 - p) / p))
        else:
            snr_lin = 10.0 ** (self.design_snr_db / 10.0)
            p_approx = 0.5 * erfc(sqrt(snr_lin))
            p_approx = float(np.clip(p_approx, 1e-12, 1.0 - 1e-12))
            self._llr_magnitude = float(np.log((1.0 - p_approx) / p_approx))

    def encode(self, data: NDArray[np.uint8]) -> NDArray[np.uint8]:
        data = self._pad_to_multiple(data, self._k)
        blocks = data.reshape(-1, self._k)
        encoded = []
        for block in blocks:
            u = np.zeros(self._n, dtype=np.uint8)
            u[self._info_indices] = block
            codeword = self._polar_transform(u)
            encoded.append(codeword)
        return np.concatenate(encoded)

    def decode(self, data: NDArray[np.uint8]) -> NDArray[np.uint8]:
        data = self._pad_to_multiple(data, self._n)
        blocks = data.reshape(-1, self._n)
        decoded = []
        mag = self._llr_magnitude
        for block in blocks:
            llr = np.where(block == 0, mag, -mag)
            if self._max_flips > 0:
                u_hat = self._sc_flip_decode(llr, block)
            else:
                u_hat = self._sc_decode(llr)
            decoded.append(u_hat[self._info_indices].astype(np.uint8))
        return np.concatenate(decoded)

    # --- Frozen-bit selection (Bhattacharyya parameter for BSC) ---

    def _compute_frozen_bits(self) -> NDArray[np.bool_]:
        """Return a boolean mask: True at frozen positions, False at info."""
        sigma2 = 1.0 / (10.0 ** (self.design_snr_db / 10.0))
        n = self._n

        z = np.full(n, np.exp(-1.0 / sigma2))

        stage = 1
        while stage < n:
            new_z = np.empty(n)
            for i in range(0, n, 2 * stage):
                for j in range(stage):
                    z_upper = z[i + j]
                    z_lower = z[i + j + stage]
                    new_z[i + j] = z_upper + z_lower - z_upper * z_lower
                    new_z[i + j + stage] = z_upper * z_lower
            z = np.clip(new_z, 0.0, 1.0)
            stage *= 2

        # Bit-reversal permutation
        z_permuted = np.empty(n)
        num_bits = int(np.log2(n))
        for i in range(n):
            rev = int(f"{i:0{num_bits}b}"[::-1], 2)
            z_permuted[rev] = z[i]

        sorted_indices = np.argsort(z_permuted)
        frozen_mask = np.ones(n, dtype=bool)
        frozen_mask[sorted_indices[: self._k]] = False
        return frozen_mask

    # --- Polar transform (bit-reversal Arikan kernel) ---

    @staticmethod
    def _polar_transform(u: NDArray[np.uint8]) -> NDArray[np.uint8]:
        """Apply the polar encoding transform x = u * G_N (mod 2)."""
        x = u.copy()
        n = len(x)
        stage = 1
        while stage < n:
            for i in range(0, n, 2 * stage):
                for j in range(stage):
                    x[i + j] = x[i + j] ^ x[i + j + stage]
            stage *= 2
        return x % 2

    # --- Successive-Cancellation (SC) decoder ---

    def _sc_decode(self, llr: NDArray[np.float64]) -> NDArray[np.uint8]:
        """Standard SC decoding on log-likelihood ratios."""
        n = self._n
        u_hat = np.zeros(n, dtype=np.uint8)
        self._sc_recursive(llr, u_hat, 0, n)
        return u_hat

    def _sc_decode_with_llrs(
        self,
        llr: NDArray[np.float64],
        constraints: dict[int, int] | None = None,
    ) -> tuple[NDArray[np.uint8], NDArray[np.float64]]:
        """SC decode returning (u_hat, per-bit LLR magnitudes)."""
        n = self._n
        u_hat = np.zeros(n, dtype=np.uint8)
        bit_llrs = np.zeros(n)
        self._sc_recursive_llr(llr, u_hat, bit_llrs, 0, n, constraints or {})
        return u_hat, bit_llrs

    def _sc_recursive(
        self,
        llr: NDArray[np.float64],
        u_hat: NDArray[np.uint8],
        start: int,
        length: int,
    ) -> NDArray[np.float64]:
        """Recursive SC decode returning partial sums for back-propagation."""
        if length == 1:
            if self._frozen_mask[start]:
                u_hat[start] = 0
            else:
                u_hat[start] = 0 if llr[0] >= 0 else 1
            return np.array([u_hat[start]], dtype=np.float64)

        half = length // 2
        llr_upper = llr[:half]
        llr_lower = llr[half:]

        f_llr = (
            np.sign(llr_upper)
            * np.sign(llr_lower)
            * np.minimum(np.abs(llr_upper), np.abs(llr_lower))
        )

        left_bits = self._sc_recursive(f_llr, u_hat, start, half)
        g_llr = llr_lower + (1 - 2 * left_bits) * llr_upper
        right_bits = self._sc_recursive(g_llr, u_hat, start + half, half)

        combined = np.empty(length, dtype=np.float64)
        combined[:half] = (
            left_bits.astype(np.uint8) ^ right_bits.astype(np.uint8)
        ).astype(np.float64)
        combined[half:] = right_bits
        return combined

    def _sc_recursive_llr(
        self,
        llr: NDArray[np.float64],
        u_hat: NDArray[np.uint8],
        bit_llrs: NDArray[np.float64],
        start: int,
        length: int,
        constraints: dict[int, int],
    ) -> NDArray[np.float64]:
        """SC decode recording per-bit LLRs and respecting constraints."""
        if length == 1:
            bit_llrs[start] = llr[0]
            if start in constraints:
                u_hat[start] = constraints[start]
            elif self._frozen_mask[start]:
                u_hat[start] = 0
            else:
                u_hat[start] = 0 if llr[0] >= 0 else 1
            return np.array([u_hat[start]], dtype=np.float64)

        half = length // 2
        llr_upper = llr[:half]
        llr_lower = llr[half:]

        f_llr = (
            np.sign(llr_upper)
            * np.sign(llr_lower)
            * np.minimum(np.abs(llr_upper), np.abs(llr_lower))
        )

        left_bits = self._sc_recursive_llr(
            f_llr, u_hat, bit_llrs, start, half, constraints
        )
        g_llr = llr_lower + (1 - 2 * left_bits) * llr_upper
        right_bits = self._sc_recursive_llr(
            g_llr, u_hat, bit_llrs, start + half, half, constraints
        )

        combined = np.empty(length, dtype=np.float64)
        combined[:half] = (
            left_bits.astype(np.uint8) ^ right_bits.astype(np.uint8)
        ).astype(np.float64)
        combined[half:] = right_bits
        return combined

    # --- SC-Flip decoder ---

    def _sc_flip_decode(
        self, channel_llr: NDArray[np.float64], received: NDArray[np.uint8]
    ) -> NDArray[np.uint8]:
        """SC-Flip decoder: run SC, then try flipping least-reliable bits.

        1. Run SC decode, recording per-bit LLR reliability.
        2. Re-encode and count mismatches with the received word.
        3. If imperfect, try flipping each of the *max_flips* least-reliable
           information bits and re-decoding from scratch with that bit
           constrained.  Keep the candidate with the fewest mismatches.
        """
        # Standard SC with LLR recording
        u_hat, bit_llrs = self._sc_decode_with_llrs(channel_llr)
        x_hat = self._polar_transform(u_hat.copy())
        best_mismatches = int(np.sum(x_hat != received))
        best_u = u_hat

        if best_mismatches == 0:
            return best_u

        # Rank info bits by reliability (ascending = least reliable first)
        info_reliability = np.abs(bit_llrs[self._info_indices])
        flip_order = self._info_indices[np.argsort(info_reliability)]

        for flip_pos in flip_order[: self._max_flips]:
            flipped_val = 1 - u_hat[flip_pos]
            constraints = {int(flip_pos): int(flipped_val)}
            u_trial, _ = self._sc_decode_with_llrs(channel_llr, constraints)
            x_trial = self._polar_transform(u_trial.copy())
            mismatches = int(np.sum(x_trial != received))

            if mismatches < best_mismatches:
                best_mismatches = mismatches
                best_u = u_trial
                if best_mismatches == 0:
                    break

        return best_u
