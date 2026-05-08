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
    original_bits: Any  # NDArray[np.uint8]
    encoded_bits: Any
    noisy_bits: Any
    decoded_bits: Any
    stats: Statistics


@dataclass
class Channel:
    code: ErrorCorrectionCode
    noise: NoiseModel
    seed: int | None = None
    _rng: Any = field(init=False, repr=False)

    def __post_init__(self) -> None:
        self._rng = np.random.default_rng(self.seed)

    def transmit(self, bits: NDArray[np.uint8]) -> ChannelResult:
        original = bits.copy()

        t0 = time.perf_counter()
        encoded = self.code.encode(original)
        encode_time = time.perf_counter() - t0

        noisy = self.noise.apply(encoded, self._rng)

        from ecc.codes.polar import PolarCode

        if isinstance(self.code, PolarCode):
            ber = self.noise.expected_ber()
            if not np.isnan(ber) and ber > 0:
                self.code.set_channel_p(ber)
        t0 = time.perf_counter()
        decoded = self.code.decode(noisy)
        decode_time = time.perf_counter() - t0

        decoded = decoded[: len(original)]
        if len(decoded) < len(original):
            decoded = np.concatenate(
                [decoded, np.zeros(len(original) - len(decoded), dtype=np.uint8)]
            )

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
