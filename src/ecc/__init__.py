"""Error Correction Codes library — Hamming, Reed-Solomon, and Polar codes."""


def __getattr__(name: str):  # noqa: N807
    """Lazy imports to avoid circular dependencies with mypyc-compiled modules."""
    _imports = {
        "Channel": "ecc.channel.channel",
        "BinarySymmetricChannel": "ecc.channel.noise",
        "BurstErrorChannel": "ecc.channel.noise",
        "NoiseModel": "ecc.channel.noise",
        "ErrorCorrectionCode": "ecc.codes.base",
        "HammingCode": "ecc.codes.hamming",
        "PolarCode": "ecc.codes.polar",
        "ReedSolomonCode": "ecc.codes.reed_solomon",
        "BinaryConverter": "ecc.core.binary",
        "Message": "ecc.core.message",
        "Statistics": "ecc.stats.metrics",
        "Visualizer": "ecc.visualization.plots",
    }
    if name in _imports:
        import importlib

        module = importlib.import_module(_imports[name])
        return getattr(module, name)
    raise AttributeError(f"module 'ecc' has no attribute {name!r}")


__all__ = [
    "BinaryConverter",
    "BinarySymmetricChannel",
    "BurstErrorChannel",
    "Channel",
    "ErrorCorrectionCode",
    "HammingCode",
    "Message",
    "NoiseModel",
    "PolarCode",
    "ReedSolomonCode",
    "Statistics",
    "Visualizer",
]
