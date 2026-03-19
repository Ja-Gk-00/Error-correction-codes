"""Tests for HammingCode — encoding, decoding, and error correction."""

import numpy as np
import pytest

from ecc.codes.hamming import HammingCode


class TestHammingProperties:
    @pytest.mark.parametrize("r", [2, 3, 4, 5])
    def test_block_sizes(self, r):
        hc = HammingCode(r=r, secded=False)
        n = 2**r - 1
        k = n - r
        assert f"Hamming({n},{k})" in hc.name
        assert hc.code_rate == pytest.approx(k / n)

    def test_secded_name(self):
        hc = HammingCode(r=3, secded=True)
        assert "SECDED" in hc.name

    def test_invalid_r(self):
        with pytest.raises(ValueError):
            HammingCode(r=1)


class TestHammingRoundtrip:
    @pytest.mark.parametrize("r", [2, 3, 4, 5])
    def test_noiseless_roundtrip(self, r, random_bits):
        hc = HammingCode(r=r, secded=False)
        encoded = hc.encode(random_bits)
        decoded = hc.decode(encoded)[: len(random_bits)]
        np.testing.assert_array_equal(decoded, random_bits)

    @pytest.mark.parametrize("r", [2, 3, 4, 5])
    def test_noiseless_roundtrip_secded(self, r, random_bits):
        hc = HammingCode(r=r, secded=True)
        encoded = hc.encode(random_bits)
        decoded = hc.decode(encoded)[: len(random_bits)]
        np.testing.assert_array_equal(decoded, random_bits)

    def test_encode_expands_data(self, random_bits):
        hc = HammingCode(r=3)
        encoded = hc.encode(random_bits)
        assert len(encoded) > len(random_bits)


class TestHammingSingleBitCorrection:
    @pytest.mark.parametrize("r", [2, 3, 4])
    def test_corrects_1bit_per_block(self, r):
        """Flip exactly 1 bit in each block — should be perfectly corrected."""
        hc = HammingCode(r=r, secded=False)
        n = 2**r - 1
        k = n - r
        # Use enough data for several blocks
        data = np.zeros(k * 4, dtype=np.uint8)
        data[::2] = 1
        encoded = hc.encode(data)

        rng = np.random.default_rng(123)
        noisy = encoded.copy()
        for i in range(0, len(noisy), n):
            flip_pos = rng.integers(0, min(n, len(noisy) - i))
            noisy[i + flip_pos] ^= 1

        decoded = hc.decode(noisy)[: len(data)]
        np.testing.assert_array_equal(decoded, data)

    def test_secded_corrects_1bit(self):
        hc = HammingCode(r=3, secded=True)
        data = np.array([1, 0, 1, 1], dtype=np.uint8)
        encoded = hc.encode(data)

        for pos in range(len(encoded)):
            noisy = encoded.copy()
            noisy[pos] ^= 1
            decoded = hc.decode(noisy)[: len(data)]
            np.testing.assert_array_equal(
                decoded, data, err_msg=f"Failed to correct bit flip at position {pos}"
            )


class TestHammingDoesNotMutateInput:
    def test_encode_preserves_input(self, random_bits):
        hc = HammingCode(r=3)
        original = random_bits.copy()
        hc.encode(random_bits)
        np.testing.assert_array_equal(random_bits, original)

    def test_decode_preserves_input(self, random_bits):
        hc = HammingCode(r=3)
        encoded = hc.encode(random_bits)
        encoded_copy = encoded.copy()
        hc.decode(encoded)
        np.testing.assert_array_equal(encoded, encoded_copy)
