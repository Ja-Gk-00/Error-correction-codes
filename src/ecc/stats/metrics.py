"""Performance metrics for error-correction experiments."""

from dataclasses import dataclass

import numpy as np
from numpy.typing import NDArray

from ecc.channel.noise import NoiseModel
from ecc.codes.base import ErrorCorrectionCode


@dataclass
class Statistics:
    """Aggregated statistics for a single encode -> noise -> decode run.

    All rates are expressed as fractions in ``[0, 1]``.
    """

    # --- Identification ---
    code_name: str
    noise_name: str

    # --- Error rates ---
    ber_before_decode: float  # BER of noisy encoded stream vs. clean encoded stream
    ber_after_decode: float  # BER of decoded stream vs. original data
    bit_errors_before: int
    bit_errors_after: int

    # --- Code properties ---
    code_rate: float
    redundancy_ratio: float
    original_bits: int
    encoded_bits: int
    overhead_bits: int

    # --- Timing ---
    encode_time_s: float
    decode_time_s: float
    throughput_kbps: float  # original bits / total time

    # --- Derived ---
    correction_effectiveness: float  # fraction of channel errors corrected

    @classmethod
    def compute(
        cls,
        original_bits: NDArray[np.uint8],
        encoded_bits: NDArray[np.uint8],
        noisy_bits: NDArray[np.uint8],
        decoded_bits: NDArray[np.uint8],
        code: ErrorCorrectionCode,
        noise: NoiseModel,
        encode_time: float,
        decode_time: float,
    ) -> Statistics:
        bit_errors_before = int(np.sum(encoded_bits != noisy_bits))
        bit_errors_after = int(np.sum(original_bits != decoded_bits))

        n_encoded = len(encoded_bits)
        n_original = len(original_bits)

        ber_before = bit_errors_before / n_encoded if n_encoded else 0.0
        ber_after = bit_errors_after / n_original if n_original else 0.0

        total_time = encode_time + decode_time
        throughput = (n_original / 1000.0) / total_time if total_time > 0 else float("inf")

        if bit_errors_before > 0:
            # Scale channel errors to data-bit equivalent
            channel_errors_data_equiv = bit_errors_before * (n_original / n_encoded)
            corrected = max(0.0, channel_errors_data_equiv - bit_errors_after)
            effectiveness = corrected / channel_errors_data_equiv
        else:
            effectiveness = 1.0

        return cls(
            code_name=code.name,
            noise_name=noise.name,
            ber_before_decode=ber_before,
            ber_after_decode=ber_after,
            bit_errors_before=bit_errors_before,
            bit_errors_after=bit_errors_after,
            code_rate=code.code_rate,
            redundancy_ratio=code.redundancy_ratio,
            original_bits=n_original,
            encoded_bits=n_encoded,
            overhead_bits=n_encoded - n_original,
            encode_time_s=encode_time,
            decode_time_s=decode_time,
            throughput_kbps=throughput,
            correction_effectiveness=effectiveness,
        )

    def summary(self) -> str:
        """One-line human-readable summary."""
        return (
            f"{self.code_name} | {self.noise_name} | "
            f"BER: {self.ber_after_decode:.6f} | "
            f"Errors fixed: "
            f"{self.bit_errors_before - self.bit_errors_after}/{self.bit_errors_before} | "
            f"Effectiveness: {self.correction_effectiveness:.1%} | "
            f"Rate: {self.code_rate:.3f} | "
            f"Time: {self.encode_time_s + self.decode_time_s:.3f}s"
        )

    def to_dict(self) -> dict[str, float | int | str]:
        """Return all fields as a flat dictionary (useful for DataFrames)."""
        return {
            "code": self.code_name,
            "noise": self.noise_name,
            "ber_channel": self.ber_before_decode,
            "ber_decoded": self.ber_after_decode,
            "bit_errors_channel": self.bit_errors_before,
            "bit_errors_decoded": self.bit_errors_after,
            "code_rate": self.code_rate,
            "redundancy_ratio": self.redundancy_ratio,
            "original_bits": self.original_bits,
            "encoded_bits": self.encoded_bits,
            "overhead_bits": self.overhead_bits,
            "encode_time_s": self.encode_time_s,
            "decode_time_s": self.decode_time_s,
            "throughput_kbps": self.throughput_kbps,
            "correction_effectiveness": self.correction_effectiveness,
        }
