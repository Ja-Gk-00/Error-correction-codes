"""Statistics and metrics for error correction benchmarking."""


def __getattr__(name: str):  # noqa: N807
    _imports = {
        "Statistics": "ecc.stats.metrics",
    }
    if name in _imports:
        import importlib

        module = importlib.import_module(_imports[name])
        return getattr(module, name)
    raise AttributeError(f"module 'ecc.stats' has no attribute {name!r}")


__all__ = ["Statistics"]
