"""Abstract base class for all error correction codes."""

from abc import ABC, abstractmethod

import numpy as np
from numpy.typing import NDArray


class ErrorCorrectionCode(ABC):
    """Base interface that every error-correction code must implement.

    Subclasses encode/decode **binary** data represented as 1-D ``uint8``
    arrays of 0s and 1s.
    """

    # --- Abstract interface ---

    @property
    @abstractmethod
    def name(self) -> str:
        """Human-readable name of the code (e.g. ``'Hamming(7,4)'``)."""

    @property
    @abstractmethod
    def code_rate(self) -> float:
        """Ratio *k / n* — fraction of data bits in a codeword."""

    @property
    @abstractmethod
    def redundancy_ratio(self) -> float:
        """Ratio *(n - k) / k* — redundancy overhead relative to data size."""

    @property
    @abstractmethod
    def error_correction_capability(self) -> str:
        """Human-readable description of how many errors the code can correct."""

    @abstractmethod
    def encode(self, data: NDArray[np.uint8]) -> NDArray[np.uint8]:
        """Encode a binary stream, returning the encoded (longer) stream."""

    @abstractmethod
    def decode(self, data: NDArray[np.uint8]) -> NDArray[np.uint8]:
        """Decode a (possibly corrupted) binary stream back to the original length."""

    # --- Helpers available to all subclasses ---

    @staticmethod
    def _pad_to_multiple(data: NDArray[np.uint8], block_size: int) -> NDArray[np.uint8]:
        """Zero-pad *data* so its length is a multiple of *block_size*."""
        remainder = len(data) % block_size
        if remainder:
            padding = np.zeros(block_size - remainder, dtype=np.uint8)
            return np.concatenate([data, padding])
        return data

    def __repr__(self) -> str:
        return (
            f"{self.__class__.__name__}(name={self.name!r}, "
            f"rate={self.code_rate:.3f}, "
            f"correction={self.error_correction_capability!r})"
        )
