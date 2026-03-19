"""Error correction code implementations."""


def __getattr__(name: str):  # noqa: N807
    _imports = {
        "ErrorCorrectionCode": "ecc.codes.base",
        "HammingCode": "ecc.codes.hamming",
        "PolarCode": "ecc.codes.polar",
        "ReedSolomonCode": "ecc.codes.reed_solomon",
    }
    if name in _imports:
        import importlib

        module = importlib.import_module(_imports[name])
        return getattr(module, name)
    raise AttributeError(f"module 'ecc.codes' has no attribute {name!r}")


__all__ = ["ErrorCorrectionCode", "HammingCode", "PolarCode", "ReedSolomonCode"]
