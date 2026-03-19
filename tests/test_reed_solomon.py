"""Tests for ReedSolomonCode — encoding, decoding, and byte-error correction."""

import numpy as np
import pytest

from ecc.codes.reed_solomon import ReedSolomonCode


class TestRSProperties:
    def test_defaults(self):
        rs = ReedSolomonCode()
        assert rs.nsym == 10
        assert rs.code_rate == pytest.approx(245 / 255)
        assert "5" in rs.error_correction_capability  # corrects 5 bytes

    def test_custom_nsym(self):
        rs = ReedSolomonCode(nsym=32)
        assert rs.code_rate == pytest.approx(223 / 255)

    def test_invalid_nsym(self):
        with pytest.raises(ValueError):
            ReedSolomonCode(nsym=0)
        with pytest.raises(ValueError):
            ReedSolomonCode(nsym=255)


class TestRSRoundtrip:
    @pytest.mark.parametrize("nsym", [10, 20, 50])
    def test_noiseless_roundtrip(self, nsym, random_bits):
        rs = ReedSolomonCode(nsym=nsym)
        encoded = rs.encode(random_bits)
        decoded = rs.decode(encoded)[: len(random_bits)]
        np.testing.assert_array_equal(decoded, random_bits)

    def test_short_message(self):
        """Even a very short message should roundtrip correctly."""
        rs = ReedSolomonCode(nsym=10)
        data = np.array([1, 0, 1, 0, 1, 0, 1, 0], dtype=np.uint8)
        encoded = rs.encode(data)
        decoded = rs.decode(encoded)[: len(data)]
        np.testing.assert_array_equal(decoded, data)

    def test_encode_expands_data(self, random_bits):
        rs = ReedSolomonCode(nsym=10)
        encoded = rs.encode(random_bits)
        assert len(encoded) > len(random_bits)


class TestRSByteErrorCorrection:
    def test_corrects_within_capacity(self):
        """Corrupt up to t=nsym//2 bytes — should be fully corrected."""
        nsym = 20
        t = nsym // 2  # can correct 10 byte errors
        rs = ReedSolomonCode(nsym=nsym)

        data = np.zeros(245 * 8, dtype=np.uint8)  # exactly 1 RS block of data
        data[::3] = 1
        encoded = rs.encode(data)

        # Corrupt t bytes in the encoded stream (flip all 8 bits of each)
        encoded_bytes = np.packbits(encoded)
        rng = np.random.default_rng(42)
        corrupt_positions = rng.choice(len(encoded_bytes), size=t, replace=False)
        for pos in corrupt_positions:
            encoded_bytes[pos] ^= 0xFF

        noisy_bits = np.unpackbits(encoded_bytes).astype(np.uint8)
        decoded = rs.decode(noisy_bits)[: len(data)]
        np.testing.assert_array_equal(decoded, data)


class TestRSPerBlockDecode:
    def test_one_bad_block_doesnt_kill_good_blocks(self):
        """If one block is uncorrectable, other blocks should still be corrected."""
        rs = ReedSolomonCode(nsym=10)
        # 2 full blocks worth of data
        data = np.zeros(245 * 2 * 8, dtype=np.uint8)
        data[::2] = 1
        encoded = rs.encode(data)

        enc_bytes = np.packbits(encoded)
        # Corrupt block 0 beyond repair (flip 100 bytes)
        for i in range(100):
            enc_bytes[i] ^= 0xFF
        # Leave block 1 clean

        noisy_bits = np.unpackbits(enc_bytes).astype(np.uint8)
        decoded = rs.decode(noisy_bits)

        # Block 1 data should be perfectly recovered
        block1_start = 245 * 8
        block1_end = 245 * 2 * 8
        np.testing.assert_array_equal(
            decoded[block1_start:block1_end], data[block1_start:block1_end]
        )
