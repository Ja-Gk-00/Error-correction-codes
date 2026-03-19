"""Noise models for simulating channel errors on binary data."""

from abc import ABC, abstractmethod

import numpy as np
from numpy.typing import NDArray


class NoiseModel(ABC):
    """Abstract base for noise models that corrupt a binary stream."""

    @property
    @abstractmethod
    def name(self) -> str:
        """Human-readable identifier."""

    @property
    @abstractmethod
    def description(self) -> str:
        """Short description of the noise model and its parameters."""

    @abstractmethod
    def apply(
        self, data: NDArray[np.uint8], rng: np.random.Generator | None = None
    ) -> NDArray[np.uint8]:
        """Return a noisy copy of *data* (0/1 array). Original is not mutated."""

    def expected_ber(self) -> float:
        """Expected bit-error rate (if analytically known), else ``NaN``."""
        return float("nan")

    def __repr__(self) -> str:
        return f"{self.__class__.__name__}({self.description})"


class BinarySymmetricChannel(NoiseModel):
    """Binary Symmetric Channel (BSC) — each bit is flipped independently with probability *p*.

    Parameters
    ----------
    p:
        Crossover (bit-flip) probability.  ``0.0`` = no noise, ``0.5`` = random.
    """

    def __init__(self, p: float = 0.01) -> None:
        if not 0.0 <= p <= 1.0:
            raise ValueError("p must be in [0, 1]")
        self.p = p

    @property
    def name(self) -> str:
        return f"BSC(p={self.p})"

    @property
    def description(self) -> str:
        return f"Binary Symmetric Channel with flip probability p={self.p}"

    def apply(
        self, data: NDArray[np.uint8], rng: np.random.Generator | None = None
    ) -> NDArray[np.uint8]:
        if rng is None:
            rng = np.random.default_rng()
        flip_mask = rng.random(len(data)) < self.p
        noisy = data.copy()
        noisy[flip_mask] ^= 1
        return noisy

    def expected_ber(self) -> float:
        return self.p


class BurstErrorChannel(NoiseModel):
    """Burst-error channel — errors occur in contiguous bursts.

    Parameters
    ----------
    burst_prob:
        Probability that a burst starts at any given bit position.
    burst_length:
        Fixed length (in bits) of each error burst.
    """

    def __init__(self, burst_prob: float = 0.005, burst_length: int = 8) -> None:
        if not 0.0 <= burst_prob <= 1.0:
            raise ValueError("burst_prob must be in [0, 1]")
        if burst_length < 1:
            raise ValueError("burst_length must be >= 1")
        self.burst_prob = burst_prob
        self.burst_length = burst_length

    @property
    def name(self) -> str:
        return f"Burst(p={self.burst_prob}, L={self.burst_length})"

    @property
    def description(self) -> str:
        return (
            f"Burst error channel: burst probability={self.burst_prob}, "
            f"burst length={self.burst_length} bits"
        )

    def apply(
        self, data: NDArray[np.uint8], rng: np.random.Generator | None = None
    ) -> NDArray[np.uint8]:
        if rng is None:
            rng = np.random.default_rng()
        noisy = data.copy()
        n = len(data)
        starts = np.where(rng.random(n) < self.burst_prob)[0]
        for s in starts:
            end = min(s + self.burst_length, n)
            noisy[s:end] ^= 1
        return noisy


# --- Preset noise levels for experiments ---

NOISE_PRESETS: dict[str, NoiseModel] = {
    "small": BinarySymmetricChannel(p=0.001),
    "medium": BinarySymmetricChannel(p=0.01),
    "large": BinarySymmetricChannel(p=0.05),
}
