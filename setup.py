"""Build script for compiling ECC modules with mypyc.

Usage
-----
    # Compile in-place (development):
    python setup.py build_ext --inplace

    # Or via the convenience script:
    python build.py

Compiled modules
----------------
- ecc.codes.hamming, reed_solomon
- ecc.codes.base excluded (ABC base — compiled classes can't be subclassed by interpreted)
- ecc.codes.polar excluded (mypyc adds overhead to its recursive SC decoder)
- ecc.core.binary, message
- ecc.channel.channel, noise
- ecc.stats.metrics

Each module is compiled independently to avoid circular init
dependencies in the multi-module shared library.
"""

import os
import sys

from setuptools import setup

# Ensure src/ is on the path so mypyc can resolve imports
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "src"))

from mypyc.build import mypycify

# Each list entry is compiled as a separate shared library.
# This avoids circular init issues when modules import each other.
modules = [
    # base.py NOT compiled: abstract ABC that subclasses (incl. uncompiled polar) inherit from.
    # Compiled classes cannot be subclassed by interpreted classes.
    ["src/ecc/core/binary.py"],
    ["src/ecc/core/message.py"],
    ["src/ecc/channel/noise.py"],
    ["src/ecc/stats/metrics.py"],
    ["src/ecc/codes/hamming.py"],
    ["src/ecc/codes/reed_solomon.py"],
    # polar.py NOT compiled: mypyc adds overhead to its deep recursive SC decoder
    ["src/ecc/channel/channel.py"],
]

ext_modules = []
for group in modules:
    ext_modules.extend(
        mypycify(
            group,
            opt_level="1",
            debug_level="0",
        )
    )

setup(
    name="error-correction-codes",
    version="0.1.0",
    packages=["ecc", "ecc.codes", "ecc.core", "ecc.channel", "ecc.stats"],
    package_dir={"": "src"},
    ext_modules=ext_modules,
)
