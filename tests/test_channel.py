"""Tests for Channel — end-to-end encode → noise → decode pipeline."""

import numpy as np
import pytest

from ecc.channel.channel import Channel, ChannelResult
from ecc.channel.noise import BinarySymmetricChannel
from ecc.codes.hamming import HammingCode
from ecc.codes.reed_solomon import ReedSolomonCode
from ecc.codes.polar import PolarCode


class TestChannelResult:
    def test_transmit_returns_channel_result(self, random_bits):
        ch = Channel(
            code=HammingCode(r=3),
            noise=BinarySymmetricChannel(p=0.01),
            seed=42,
        )
        result = ch.transmit(random_bits)
        assert isinstance(result, ChannelResult)
        assert len(result.original_bits) == len(random_bits)
        assert len(result.decoded_bits) == len(random_bits)
        assert len(result.encoded_bits) > len(random_bits)

    def test_stats_populated(self, random_bits):
        ch = Channel(
            code=HammingCode(r=3),
            noise=BinarySymmetricChannel(p=0.01),
            seed=42,
        )
        result = ch.transmit(random_bits)
        s = result.stats
        assert s.code_name != ""
        assert s.noise_name != ""
        assert 0 <= s.ber_after_decode <= 1
        assert s.encode_time_s >= 0
        assert s.decode_time_s >= 0


class TestChannelNoiseless:
    @pytest.mark.parametrize(
        "code",
        [
            HammingCode(r=3, secded=True),
            ReedSolomonCode(nsym=10),
            PolarCode(n=64, k=32, max_flips=0),
        ],
        ids=["hamming", "rs", "polar"],
    )
    def test_noiseless_perfect_recovery(self, code, random_bits):
        ch = Channel(code=code, noise=BinarySymmetricChannel(p=0.0), seed=0)
        result = ch.transmit(random_bits)
        np.testing.assert_array_equal(result.decoded_bits, random_bits)
        assert result.stats.ber_after_decode == 0.0


class TestChannelReproducibility:
    def test_same_seed_same_result(self, random_bits):
        code = HammingCode(r=3)
        noise = BinarySymmetricChannel(p=0.05)

        ch1 = Channel(code=code, noise=noise, seed=99)
        ch2 = Channel(code=code, noise=noise, seed=99)

        r1 = ch1.transmit(random_bits)
        r2 = ch2.transmit(random_bits)

        np.testing.assert_array_equal(r1.noisy_bits, r2.noisy_bits)
        np.testing.assert_array_equal(r1.decoded_bits, r2.decoded_bits)

    def test_different_seed_different_noise(self, random_bits):
        code = HammingCode(r=3)
        noise = BinarySymmetricChannel(p=0.1)

        ch1 = Channel(code=code, noise=noise, seed=1)
        ch2 = Channel(code=code, noise=noise, seed=2)

        r1 = ch1.transmit(random_bits)
        r2 = ch2.transmit(random_bits)

        # Very unlikely to be identical with different seeds
        assert not np.array_equal(r1.noisy_bits, r2.noisy_bits)


class TestChannelECCImproves:
    def test_hamming_reduces_ber(self, random_bits):
        p = 0.01
        ch = Channel(code=HammingCode(r=3, secded=True), noise=BinarySymmetricChannel(p=p), seed=42)
        result = ch.transmit(random_bits)
        assert result.stats.ber_after_decode < p

    def test_polar_reduces_ber(self, random_bits):
        p = 0.01
        ch = Channel(code=PolarCode(n=64, k=32, max_flips=4), noise=BinarySymmetricChannel(p=p), seed=42)
        result = ch.transmit(random_bits)
        assert result.stats.ber_after_decode < p
