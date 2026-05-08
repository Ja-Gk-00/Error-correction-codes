from dataclasses import dataclass, field
from typing import Any

import numpy as np
from numpy.typing import NDArray

from ecc.core.binary import BinaryConverter


@dataclass
class Message:
    data: Any
    data_type: str
    bits: Any  # NDArray[np.uint8]
    metadata: dict[str, Any] = field(default_factory=dict)

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
        return cls(data=bits, data_type="bits", bits=bits.astype(np.uint8))

    def reconstruct(self, bits: NDArray[np.uint8]) -> Any:
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

    @property
    def bit_length(self) -> int:
        return len(self.bits)

    def __len__(self) -> int:
        return self.bit_length

    def __repr__(self) -> str:
        return f"Message(type={self.data_type!r}, bits={self.bit_length}, metadata={self.metadata})"
