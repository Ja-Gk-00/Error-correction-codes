"""Message container that wraps raw data with its binary representation."""

from dataclasses import dataclass, field
from typing import Any

import numpy as np
from numpy.typing import NDArray

from ecc.core.binary import BinaryConverter


@dataclass
class Message:
    """Immutable wrapper around a chunk of data and its binary form.

    Parameters
    ----------
    data:
        The original payload (``bytes``, ``str``, ``int``, or image ``NDArray``).
    data_type:
        One of ``"bytes"``, ``"str"``, ``"int"``, ``"image"``.
        Inferred automatically when *data* is passed to :meth:`from_data`.
    bits:
        Binary representation as a 1-D ``uint8`` array of 0/1 values.
    metadata:
        Arbitrary extra information (e.g. image shape, encoding).
    """

    data: Any
    data_type: str
    bits: Any  # NDArray[np.uint8] — typed as Any for mypyc compat
    metadata: dict[str, Any] = field(default_factory=dict)

    # --- Constructors ---

    @classmethod
    def from_bytes(cls, data: bytes) -> Message:
        bits = BinaryConverter.bytes_to_binary(data)
        return cls(data=data, data_type="bytes", bits=bits)

    @classmethod
    def from_str(cls, text: str, encoding: str = "utf-8") -> Message:
        bits = BinaryConverter.str_to_binary(text, encoding)
        return cls(data=text, data_type="str", bits=bits, metadata={"encoding": encoding})

    @classmethod
    def from_int(cls, value: int, bit_width: int = 32) -> Message:
        bits = BinaryConverter.int_to_binary(value, bit_width)
        return cls(data=value, data_type="int", bits=bits, metadata={"bit_width": bit_width})

    @classmethod
    def from_image(cls, image_array: NDArray[np.uint8]) -> Message:
        bits, shape = BinaryConverter.image_to_binary(image_array)
        return cls(
            data=image_array,
            data_type="image",
            bits=bits,
            metadata={"shape": shape},
        )

    @classmethod
    def from_bits(cls, bits: NDArray[np.uint8]) -> Message:
        """Create a message from raw bits (data_type='bits')."""
        return cls(data=bits, data_type="bits", bits=bits.astype(np.uint8))

    # --- Reconstruction ---

    def reconstruct(self, bits: NDArray[np.uint8]) -> Any:
        """Reconstruct the original data type from (possibly corrupted) bits."""
        if self.data_type == "bytes":
            return BinaryConverter.binary_to_bytes(bits)
        if self.data_type == "str":
            enc = self.metadata.get("encoding", "utf-8")
            return BinaryConverter.binary_to_str(bits, enc)
        if self.data_type == "int":
            return BinaryConverter.binary_to_int(bits)
        if self.data_type == "image":
            return BinaryConverter.binary_to_image(bits, self.metadata["shape"])
        return bits

    # --- Utilities ---

    @property
    def bit_length(self) -> int:
        return len(self.bits)

    def __len__(self) -> int:
        return self.bit_length

    def __repr__(self) -> str:
        return f"Message(type={self.data_type!r}, bits={self.bit_length}, metadata={self.metadata})"
