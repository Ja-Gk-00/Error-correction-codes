"""End-to-end channel simulation: encode -> noise -> decode."""

import time
from dataclasses import dataclass, field

from typing import Any

import numpy as np
from numpy.typing import NDArray

from ecc.channel.noise import NoiseModel
from ecc.codes.base import ErrorCorrectionCode
from ecc.stats.metrics import Statistics


@dataclass
class ChannelResult:
    """Full record of a single transmission through a :class:`Channel`.

    Attributes
    ----------
    original_bits:  The input bit stream (NDArray[np.uint8]).
    encoded_bits:   Output of the encoder.
    noisy_bits:     Encoded bits after passing through the noise model.
    decoded_bits:   Output of the decoder (should match *original_bits*).
    stats:          Computed performance statistics.
    """

    original_bits: Any  # NDArray[np.uint8] — typed as Any for mypyc compat
    encoded_bits: Any
    noisy_bits: Any
    decoded_bits: Any
    stats: Statistics


@dataclass
class Channel:
    """Simulates a noisy communication channel with ECC protection.

    Parameters
    ----------
    code:
        Error-correction codec.
    noise:
        Noise model to apply between encoding and decoding.
    seed:
        Optional RNG seed for reproducibility.
    """

    code: ErrorCorrectionCode
    noise: NoiseModel
    seed: int | None = None
    _rng: Any = field(init=False, repr=False)  # np.random.Generator

    def __post_init__(self) -> None:
        self._rng = np.random.default_rng(self.seed)

    def transmit(self, bits: NDArray[np.uint8]) -> ChannelResult:
        """Run the full encode → noise → decode pipeline and collect statistics."""
        original = bits.copy()

        # Encode
        t0 = time.perf_counter()
        encoded = self.code.encode(original)
        encode_time = time.perf_counter() - t0

        # Apply noise
        noisy = self.noise.apply(encoded, self._rng)

        # Give the decoder channel information when available
        from ecc.codes.polar import PolarCode

        if isinstance(self.code, PolarCode):
            ber = self.noise.expected_ber()
            if not np.isnan(ber) and ber > 0:
                self.code.set_channel_p(ber)

        # Decode
        t0 = time.perf_counter()
        decoded = self.code.decode(noisy)
        decode_time = time.perf_counter() - t0

        # Trim decoded to original length (codes may pad)
        decoded = decoded[: len(original)]
        if len(decoded) < len(original):
            decoded = np.concatenate(
                [decoded, np.zeros(len(original) - len(decoded), dtype=np.uint8)]
            )

        # Compute statistics
        stats = Statistics.compute(
            original_bits=original,
            encoded_bits=encoded,
            noisy_bits=noisy,
            decoded_bits=decoded,
            code=self.code,
            noise=self.noise,
            encode_time=encode_time,
            decode_time=decode_time,
        )

        return ChannelResult(
            original_bits=original,
            encoded_bits=encoded,
            noisy_bits=noisy,
            decoded_bits=decoded,
            stats=stats,
        )
