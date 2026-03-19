"""Tests for BinaryConverter — roundtrip conversions for all data types."""

import numpy as np

from ecc.core.binary import BinaryConverter


class TestBytesConversion:
    def test_roundtrip(self):
        original = b"hello world"
        bits = BinaryConverter.bytes_to_binary(original)
        recovered = BinaryConverter.binary_to_bytes(bits)
        assert recovered == original

    def test_empty(self):
        bits = BinaryConverter.bytes_to_binary(b"")
        assert len(bits) == 0
        assert BinaryConverter.binary_to_bytes(bits) == b""

    def test_all_byte_values(self):
        original = bytes(range(256))
        bits = BinaryConverter.bytes_to_binary(original)
        assert len(bits) == 256 * 8
        assert BinaryConverter.binary_to_bytes(bits) == original

    def test_bits_are_binary(self):
        bits = BinaryConverter.bytes_to_binary(b"\xff\x00\xaa")
        assert set(np.unique(bits)).issubset({0, 1})


class TestStringConversion:
    def test_ascii_roundtrip(self):
        text = "Error correction codes!"
        bits = BinaryConverter.str_to_binary(text)
        assert BinaryConverter.binary_to_str(bits) == text

    def test_unicode_roundtrip(self):
        text = "Zażółć gęślą jaźń"
        bits = BinaryConverter.str_to_binary(text, encoding="utf-8")
        assert BinaryConverter.binary_to_str(bits, encoding="utf-8") == text

    def test_empty_string(self):
        bits = BinaryConverter.str_to_binary("")
        assert len(bits) == 0
        assert BinaryConverter.binary_to_str(bits) == ""


class TestIntConversion:
    def test_roundtrip_small(self):
        for v in [0, 1, 7, 42, 255]:
            bits = BinaryConverter.int_to_binary(v, bit_width=8)
            assert len(bits) == 8
            assert BinaryConverter.binary_to_int(bits) == v

    def test_roundtrip_32bit(self):
        val = 123456789
        bits = BinaryConverter.int_to_binary(val, bit_width=32)
        assert len(bits) == 32
        assert BinaryConverter.binary_to_int(bits) == val

    def test_zero(self):
        bits = BinaryConverter.int_to_binary(0, bit_width=16)
        assert np.all(bits == 0)
        assert BinaryConverter.binary_to_int(bits) == 0


class TestImageConversion:
    def test_roundtrip_rgb(self):
        img = np.arange(24, dtype=np.uint8).reshape(2, 4, 3)
        bits, shape = BinaryConverter.image_to_binary(img)
        recovered = BinaryConverter.binary_to_image(bits, shape)
        np.testing.assert_array_equal(recovered, img)

    def test_roundtrip_grayscale(self):
        img = np.array([[0, 128, 255], [1, 2, 3]], dtype=np.uint8)
        bits, shape = BinaryConverter.image_to_binary(img)
        recovered = BinaryConverter.binary_to_image(bits, shape)
        np.testing.assert_array_equal(recovered, img)

    def test_bit_count(self):
        img = np.zeros((3, 4, 3), dtype=np.uint8)
        bits, _ = BinaryConverter.image_to_binary(img)
        assert len(bits) == 3 * 4 * 3 * 8
