"""Convenience script to compile ECC modules with mypyc.

Usage
-----
    python build.py          # compile in-place
    python build.py clean    # remove build artifacts
"""

import os
import shutil
import subprocess
import sys


ROOT = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.join(ROOT, "src")


def clean() -> None:
    """Remove all mypyc / setuptools build artifacts."""
    for dirpath in ["build", "dist", "error_correction_codes.egg-info"]:
        path = os.path.join(ROOT, dirpath)
        if os.path.isdir(path):
            shutil.rmtree(path)
            print(f"  removed {dirpath}/")

    # Remove compiled .pyd / .so files next to source
    for root, _dirs, files in os.walk(SRC):
        for f in files:
            if f.endswith((".pyd", ".so", ".c")):
                full = os.path.join(root, f)
                os.remove(full)
                print(f"  removed {os.path.relpath(full, ROOT)}")

    # Remove __pycache__ dirs
    for root, dirs, _files in os.walk(SRC):
        for d in dirs:
            if d == "__pycache__":
                shutil.rmtree(os.path.join(root, d))

    print("Clean complete.")


def _clean_pycache() -> None:
    """Remove __pycache__ dirs to prevent stale bytecode shadowing compiled extensions."""
    for root, dirs, _files in os.walk(SRC):
        for d in dirs:
            if d == "__pycache__":
                shutil.rmtree(os.path.join(root, d))


def build() -> None:
    """Run mypyc compilation in-place."""
    _clean_pycache()
    print("Compiling ECC modules with mypyc...")
    print("=" * 60)
    result = subprocess.run(
        [sys.executable, "setup.py", "build_ext", "--inplace"],
        cwd=ROOT,
    )
    _clean_pycache()
    if result.returncode == 0:
        print("=" * 60)
        print("Build successful! Compiled extensions are in src/ecc/")
    else:
        print("=" * 60)
        print("Build FAILED. Check errors above.")
        sys.exit(1)


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "clean":
        clean()
    else:
        build()
