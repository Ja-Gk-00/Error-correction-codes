"""Visualization utilities for error correction experiments."""


def __getattr__(name: str):  # noqa: N807
    _imports = {
        "Visualizer": "ecc.visualization.plots",
    }
    if name in _imports:
        import importlib

        module = importlib.import_module(_imports[name])
        return getattr(module, name)
    raise AttributeError(f"module 'ecc.visualization' has no attribute {name!r}")


__all__ = ["Visualizer"]
