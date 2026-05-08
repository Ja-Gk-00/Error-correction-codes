import os
import sys

from setuptools import setup

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "src"))

from mypyc.build import mypycify

modules = [
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
