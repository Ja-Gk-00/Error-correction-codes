"""Binary conversion utilities for various data types."""

import numpy as np
from numpy.typing import NDArray


class BinaryConverter:
    """Convert between various data types and binary (NumPy arrays of 0s and 1s).

    All binary representations use ``np.uint8`` arrays containing only 0 and 1,
    with big-endian bit ordering (MSB first within each byte).
    """

    # --- bytes <-> binary ---

    @staticmethod
    def bytes_to_binary(data: bytes) -> NDArray[np.uint8]:
        """Convert raw bytes to a binary array.

        Parameters
        ----------
        data:
            Arbitrary byte string.

        Returns
        -------
        NDArray[np.uint8]
            1-D array of 0/1 values with length ``8 * len(data)``.
        """
        arr = np.frombuffer(data, dtype=np.uint8)
        return np.unpackbits(arr).astype(np.uint8)

    @staticmethod
    def binary_to_bytes(bits: NDArray[np.uint8]) -> bytes:
        """Convert a binary array back to bytes.

        Parameters
        ----------
        bits:
            1-D array of 0/1 values. Length is padded to a multiple of 8 if needed.

        Returns
        -------
        bytes
        """
        # Pad to multiple of 8
        remainder = len(bits) % 8
        if remainder:
            bits = np.concatenate([bits, np.zeros(8 - remainder, dtype=np.uint8)])
        return np.packbits(bits.astype(np.uint8)).tobytes()

    # --- str <-> binary ---

    @staticmethod
    def str_to_binary(text: str, encoding: str = "utf-8") -> NDArray[np.uint8]:
        """Encode a string as a binary array."""
        return BinaryConverter.bytes_to_binary(text.encode(encoding))

    @staticmethod
    def binary_to_str(bits: NDArray[np.uint8], encoding: str = "utf-8") -> str:
        """Decode a binary array back to a string."""
        return BinaryConverter.binary_to_bytes(bits).decode(encoding, errors="replace")

    # --- int <-> binary ---

    @staticmethod
    def int_to_binary(value: int, bit_width: int = 32) -> NDArray[np.uint8]:
        """Encode an unsigned integer into a fixed-width binary array (big-endian)."""
        if value < 0:
            raise ValueError("Only non-negative integers are supported")
        bits = np.array(
            [(value >> (bit_width - 1 - i)) & 1 for i in range(bit_width)],
            dtype=np.uint8,
        )
        return bits

    @staticmethod
    def binary_to_int(bits: NDArray[np.uint8]) -> int:
        """Decode a binary array to an unsigned integer."""
        result = 0
        for b in bits:
            result = (result << 1) | int(b)
        return result

    # --- image <-> binary ---

    @staticmethod
    def image_to_binary(
        image_array: NDArray[np.uint8],
    ) -> tuple[NDArray[np.uint8], tuple[int, ...]]:
        """Flatten an image array to a binary stream.

        Parameters
        ----------
        image_array:
            Image as a NumPy ``uint8`` array (HxW or HxWxC).

        Returns
        -------
        tuple
            ``(bits, original_shape)`` so the image can be reconstructed later.
        """
        shape = image_array.shape
        flat = image_array.flatten()
        bits = np.unpackbits(flat).astype(np.uint8)
        return bits, shape

    @staticmethod
    def binary_to_image(bits: NDArray[np.uint8], shape: tuple[int, ...]) -> NDArray[np.uint8]:
        """Reconstruct an image array from a binary stream.

        Parameters
        ----------
        bits:
            Binary array produced by :meth:`image_to_binary`.
        shape:
            Original image shape.

        Returns
        -------
        NDArray[np.uint8]
            Reconstructed image array.
        """
        n_pixels = int(np.prod(shape))
        n_bits = n_pixels * 8
        # Pad or truncate to expected length
        if len(bits) < n_bits:
            bits = np.concatenate([bits, np.zeros(n_bits - len(bits), dtype=np.uint8)])
        else:
            bits = bits[:n_bits]
        flat = np.packbits(bits.astype(np.uint8))[:n_pixels]
        return flat.reshape(shape).astype(np.uint8)
