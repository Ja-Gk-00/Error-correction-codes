"""Tests for Message — construction, properties, and reconstruction."""

import numpy as np

from ecc.core.message import Message


class TestMessageFromStr:
    def test_roundtrip(self):
        msg = Message.from_str("hello")
        assert msg.data_type == "str"
        assert msg.bit_length == len("hello") * 8
        assert msg.reconstruct(msg.bits) == "hello"

    def test_len(self):
        msg = Message.from_str("abc")
        assert len(msg) == 3 * 8


class TestMessageFromBytes:
    def test_roundtrip(self):
        data = b"\x00\xff\xab"
        msg = Message.from_bytes(data)
        assert msg.data_type == "bytes"
        assert msg.reconstruct(msg.bits) == data


class TestMessageFromInt:
    def test_roundtrip(self):
        msg = Message.from_int(42, bit_width=16)
        assert msg.data_type == "int"
        assert msg.reconstruct(msg.bits) == 42


class TestMessageFromImage:
    def test_roundtrip(self):
        img = np.random.default_rng(0).integers(0, 256, (4, 4, 3), dtype=np.uint8)
        msg = Message.from_image(img)
        assert msg.data_type == "image"
        assert "shape" in msg.metadata
        recovered = msg.reconstruct(msg.bits)
        np.testing.assert_array_equal(recovered, img)

    def test_bit_length(self):
        img = np.zeros((2, 3, 3), dtype=np.uint8)
        msg = Message.from_image(img)
        assert msg.bit_length == 2 * 3 * 3 * 8


class TestMessageFromBits:
    def test_roundtrip(self):
        bits = np.array([1, 0, 1, 1, 0], dtype=np.uint8)
        msg = Message.from_bits(bits)
        assert msg.data_type == "bits"
        np.testing.assert_array_equal(msg.reconstruct(msg.bits), bits)


class TestMessageReconstruct:
    def test_truncated_bits_str(self):
        """Reconstruction from shorter bits should still work (truncated)."""
        msg = Message.from_str("AB")
        short = msg.bits[:8]  # only first byte
        result = msg.reconstruct(short)
        assert isinstance(result, str)

    def test_corrupted_bits_image(self):
        """Image reconstruction from noisy bits returns array of correct shape."""
        img = np.zeros((3, 3, 3), dtype=np.uint8)
        msg = Message.from_image(img)
        noisy = msg.bits.copy()
        noisy[0] ^= 1  # flip one bit
        recovered = msg.reconstruct(noisy)
        assert recovered.shape == img.shape
