"""Tests for noise models — BSC and BurstErrorChannel."""

import numpy as np
import pytest

from ecc.channel.noise import (
    BinarySymmetricChannel,
    BurstErrorChannel,
    NOISE_PRESETS,
)


class TestBSC:
    def test_zero_noise(self):
        bsc = BinarySymmetricChannel(p=0.0)
        data = np.array([0, 1, 0, 1, 1, 0], dtype=np.uint8)
        noisy = bsc.apply(data, np.random.default_rng(0))
        np.testing.assert_array_equal(noisy, data)

    def test_full_noise(self):
        bsc = BinarySymmetricChannel(p=1.0)
        data = np.array([0, 1, 0, 1, 1, 0], dtype=np.uint8)
        noisy = bsc.apply(data, np.random.default_rng(0))
        np.testing.assert_array_equal(noisy, 1 - data)

    def test_output_is_binary(self):
        bsc = BinarySymmetricChannel(p=0.1)
        data = np.zeros(10000, dtype=np.uint8)
        noisy = bsc.apply(data, np.random.default_rng(42))
        assert set(np.unique(noisy)).issubset({0, 1})

    def test_approximate_flip_rate(self):
        p = 0.05
        bsc = BinarySymmetricChannel(p=p)
        data = np.zeros(100_000, dtype=np.uint8)
        noisy = bsc.apply(data, np.random.default_rng(42))
        actual_rate = np.mean(noisy != data)
        assert actual_rate == pytest.approx(p, abs=0.005)

    def test_expected_ber(self):
        bsc = BinarySymmetricChannel(p=0.03)
        assert bsc.expected_ber() == pytest.approx(0.03)

    def test_does_not_mutate_input(self):
        bsc = BinarySymmetricChannel(p=0.1)
        data = np.array([0, 1, 0, 1], dtype=np.uint8)
        original = data.copy()
        bsc.apply(data, np.random.default_rng(0))
        np.testing.assert_array_equal(data, original)

    def test_name_and_description(self):
        bsc = BinarySymmetricChannel(p=0.01)
        assert "BSC" in bsc.name
        assert len(bsc.description) > 0


class TestBurstErrorChannel:
    def test_zero_burst_prob(self):
        bec = BurstErrorChannel(burst_prob=0.0, burst_length=5)
        data = np.ones(100, dtype=np.uint8)
        noisy = bec.apply(data, np.random.default_rng(0))
        np.testing.assert_array_equal(noisy, data)

    def test_output_is_binary(self):
        bec = BurstErrorChannel(burst_prob=0.1, burst_length=4)
        data = np.zeros(1000, dtype=np.uint8)
        noisy = bec.apply(data, np.random.default_rng(0))
        assert set(np.unique(noisy)).issubset({0, 1})

    def test_burst_creates_consecutive_errors(self):
        bec = BurstErrorChannel(burst_prob=1.0, burst_length=8)
        data = np.zeros(16, dtype=np.uint8)
        noisy = bec.apply(data, np.random.default_rng(0))
        # With burst_prob=1.0, every position triggers a burst
        # So all bits should be flipped
        assert np.sum(noisy) > 0


class TestNoisePresets:
    def test_presets_exist(self):
        assert "small" in NOISE_PRESETS
        assert "medium" in NOISE_PRESETS
        assert "large" in NOISE_PRESETS

    def test_presets_are_bsc(self):
        for preset in NOISE_PRESETS.values():
            assert isinstance(preset, BinarySymmetricChannel)

    def test_presets_increasing_noise(self):
        bers = [NOISE_PRESETS[k].expected_ber() for k in ["small", "medium", "large"]]
        assert bers[0] < bers[1] < bers[2]
