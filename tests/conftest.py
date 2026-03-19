"""Shared fixtures for all tests."""

import numpy as np
import pytest


@pytest.fixture
def rng():
    """Deterministic random number generator."""
    return np.random.default_rng(42)


@pytest.fixture
def random_bits(rng):
    """1024 random bits."""
    return rng.integers(0, 2, size=1024, dtype=np.uint8)


@pytest.fixture
def small_bits(rng):
    """64 random bits (fast tests)."""
    return rng.integers(0, 2, size=64, dtype=np.uint8)
