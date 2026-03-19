"""Tests for PolarCode — encoding, decoding, SC, and SC-Flip."""

import numpy as np
import pytest

from ecc.codes.polar import PolarCode


class TestPolarProperties:
    def test_defaults(self):
        pc = PolarCode()
        assert pc.name == "Polar(256,128)"
        assert pc.code_rate == pytest.approx(0.5)

    def test_custom(self):
        pc = PolarCode(n=64, k=32, design_snr_db=2.0)
        assert pc.name == "Polar(64,32)"

    def test_invalid_n(self):
        with pytest.raises(ValueError):
            PolarCode(n=100)  # not a power of 2

    def test_invalid_k(self):
        with pytest.raises(ValueError):
            PolarCode(n=64, k=0)
        with pytest.raises(ValueError):
            PolarCode(n=64, k=65)


class TestPolarRoundtrip:
    @pytest.mark.parametrize("n,k", [(8, 4), (16, 8), (64, 32), (256, 128)])
    def test_noiseless_roundtrip(self, n, k, random_bits):
        pc = PolarCode(n=n, k=k, max_flips=0)
        bits = random_bits[:256]  # keep it short
        encoded = pc.encode(bits)
        decoded = pc.decode(encoded)[: len(bits)]
        np.testing.assert_array_equal(decoded, bits)

    def test_encode_doubles_length(self, small_bits):
        pc = PolarCode(n=16, k=8, max_flips=0)
        encoded = pc.encode(small_bits)
        assert len(encoded) == len(small_bits) * 2  # rate 1/2


class TestPolarSingleBitCorrection:
    def test_small_code_all_positions(self):
        """Polar(8,4): flip every single position — all should be corrected."""
        pc = PolarCode(n=8, k=4, max_flips=0)
        for val in range(16):
            data = np.array([(val >> i) & 1 for i in range(4)], dtype=np.uint8)
            encoded = pc.encode(data)
            for pos in range(8):
                noisy = encoded.copy()
                noisy[pos] ^= 1
                decoded = pc.decode(noisy)[:4]
                np.testing.assert_array_equal(
                    decoded, data,
                    err_msg=f"val={val}, flip pos={pos}",
                )


class TestPolarSCFlip:
    def test_flip_improves_over_sc(self):
        """SC-Flip should correct at least as many errors as plain SC."""
        pc_sc = PolarCode(n=64, k=32, max_flips=0)
        pc_flip = PolarCode(n=64, k=32, max_flips=8)

        rng = np.random.default_rng(99)
        data = rng.integers(0, 2, size=128, dtype=np.uint8)
        encoded = pc_sc.encode(data)

        # Moderate noise: flip ~5% of bits
        noisy = encoded.copy()
        flip_mask = rng.random(len(encoded)) < 0.05
        noisy[flip_mask] ^= 1

        dec_sc = pc_sc.decode(noisy)[: len(data)]
        dec_flip = pc_flip.decode(noisy)[: len(data)]

        errors_sc = np.sum(dec_sc != data)
        errors_flip = np.sum(dec_flip != data)
        assert errors_flip <= errors_sc

    def test_set_channel_p(self):
        pc = PolarCode(n=64, k=32)
        pc.set_channel_p(0.01)
        assert pc._llr_magnitude == pytest.approx(np.log(99), rel=1e-6)

        pc.set_channel_p(0.5)
        assert pc._llr_magnitude == pytest.approx(0.0, abs=1e-6)


class TestPolarFrozenBits:
    def test_frozen_count(self):
        pc = PolarCode(n=64, k=32)
        assert np.sum(pc._frozen_mask) == 32  # n - k frozen
        assert np.sum(~pc._frozen_mask) == 32  # k info

    def test_info_indices_match(self):
        pc = PolarCode(n=16, k=8)
        assert len(pc._info_indices) == 8
        assert np.all(~pc._frozen_mask[pc._info_indices])
