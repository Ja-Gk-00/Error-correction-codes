"""Tests for Statistics — computation and derived metrics."""

import numpy as np
import pytest

from ecc.channel.noise import BinarySymmetricChannel
from ecc.codes.hamming import HammingCode
from ecc.stats.metrics import Statistics


class TestStatisticsCompute:
    def _make_stats(self, n_errors_before=10, n_errors_after=2, n_bits=1000):
        original = np.zeros(n_bits, dtype=np.uint8)
        encoded = np.zeros(n_bits * 2, dtype=np.uint8)  # rate 1/2
        noisy = encoded.copy()
        noisy[:n_errors_before] = 1  # errors in encoded stream
        decoded = original.copy()
        decoded[:n_errors_after] = 1  # residual errors after decode

        code = HammingCode(r=3)
        noise = BinarySymmetricChannel(p=0.01)
        return Statistics.compute(
            original_bits=original,
            encoded_bits=encoded,
            noisy_bits=noisy,
            decoded_bits=decoded,
            code=code,
            noise=noise,
            encode_time=0.1,
            decode_time=0.2,
        )

    def test_ber_values(self):
        stats = self._make_stats(n_errors_before=10, n_errors_after=2, n_bits=1000)
        assert stats.ber_after_decode == pytest.approx(2 / 1000)
        assert stats.bit_errors_after == 2

    def test_timing(self):
        stats = self._make_stats()
        assert stats.encode_time_s == pytest.approx(0.1)
        assert stats.decode_time_s == pytest.approx(0.2)

    def test_code_name(self):
        stats = self._make_stats()
        assert "Hamming" in stats.code_name

    def test_noise_name(self):
        stats = self._make_stats()
        assert "BSC" in stats.noise_name

    def test_overhead(self):
        stats = self._make_stats(n_bits=1000)
        assert stats.original_bits == 1000
        assert stats.encoded_bits == 2000
        assert stats.overhead_bits == 1000


class TestStatisticsSummary:
    def test_summary_is_string(self):
        original = np.zeros(100, dtype=np.uint8)
        encoded = np.zeros(200, dtype=np.uint8)
        stats = Statistics.compute(
            original_bits=original,
            encoded_bits=encoded,
            noisy_bits=encoded.copy(),
            decoded_bits=original.copy(),
            code=HammingCode(r=3),
            noise=BinarySymmetricChannel(p=0.01),
            encode_time=0.01,
            decode_time=0.02,
        )
        s = stats.summary()
        assert isinstance(s, str)
        assert len(s) > 0


class TestStatisticsToDict:
    def test_to_dict_has_all_keys(self):
        original = np.zeros(100, dtype=np.uint8)
        encoded = np.zeros(200, dtype=np.uint8)
        stats = Statistics.compute(
            original_bits=original,
            encoded_bits=encoded,
            noisy_bits=encoded.copy(),
            decoded_bits=original.copy(),
            code=HammingCode(r=3),
            noise=BinarySymmetricChannel(p=0.01),
            encode_time=0.01,
            decode_time=0.02,
        )
        d = stats.to_dict()
        assert "code" in d
        assert "ber_decoded" in d
        assert "encode_time_s" in d
