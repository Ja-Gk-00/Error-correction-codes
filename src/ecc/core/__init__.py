"""Core data structures for error correction codes."""


def __getattr__(name: str):  # noqa: N807
    _imports = {
        "BinaryConverter": "ecc.core.binary",
        "Message": "ecc.core.message",
    }
    if name in _imports:
        import importlib

        module = importlib.import_module(_imports[name])
        return getattr(module, name)
    raise AttributeError(f"module 'ecc.core' has no attribute {name!r}")


__all__ = ["BinaryConverter", "Message"]
