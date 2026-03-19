"""Channel models and noise simulation."""


def __getattr__(name: str):  # noqa: N807
    """Lazy imports to avoid circular dependencies with mypyc-compiled modules."""
    _imports = {
        "Channel": "ecc.channel.channel",
        "BinarySymmetricChannel": "ecc.channel.noise",
        "BurstErrorChannel": "ecc.channel.noise",
        "NoiseModel": "ecc.channel.noise",
    }
    if name in _imports:
        import importlib

        module = importlib.import_module(_imports[name])
        return getattr(module, name)
    raise AttributeError(f"module 'ecc.channel' has no attribute {name!r}")


__all__ = ["BinarySymmetricChannel", "BurstErrorChannel", "Channel", "NoiseModel"]
