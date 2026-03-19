# Error Correction Codes

A comprehensive Python library for simulating, benchmarking, and visualizing **error correction codes** (ECC) over noisy communication channels.

## Implemented Codes

| Code | Class | Parameters | Capability |
|------|-------|-----------|------------|
| **Hamming** | `HammingCode(r, secded)` | `r` = parity bits (default 3 → 7,4 code) | Corrects 1-bit errors per block; SECDED detects 2-bit errors |
| **Reed-Solomon** | `ReedSolomonCode(nsym)` | `nsym` = ECC symbols (default 10) | Corrects up to `nsym/2` *byte* errors per 255-byte block |
| **Polar** | `PolarCode(n, k, design_snr_db)` | `n` = code length, `k` = info bits | Capacity-approaching; successive-cancellation decoding |

## Architecture

```
src/ecc/
├── core/
│   ├── binary.py          # BinaryConverter — bytes/str/int/image ↔ binary arrays
│   └── message.py         # Message — wraps data + binary repr + metadata
├── codes/
│   ├── base.py            # ErrorCorrectionCode (ABC)
│   ├── hamming.py         # Hamming(2^r−1, 2^r−1−r) with SECDED
│   ├── reed_solomon.py    # RS(255, 255−nsym) over GF(2^8)
│   └── polar.py           # Polar(N, K) with SC decoding
├── channel/
│   ├── noise.py           # NoiseModel, BinarySymmetricChannel, BurstErrorChannel
│   └── channel.py         # Channel — encode → noise → decode pipeline
├── stats/
│   └── metrics.py         # Statistics — BER, timing, effectiveness metrics
└── visualization/
    └── plots.py           # Visualizer — image comparison, BER charts, heatmaps
```

### Key Classes

- **`BinaryConverter`** — static methods for converting `bytes`, `str`, `int`, and image `ndarray` to/from binary (`uint8` arrays of 0/1).
- **`Message`** — immutable wrapper: holds original data, its binary representation, and metadata (e.g. image shape). Supports reconstruction from (possibly corrupted) bits.
- **`ErrorCorrectionCode`** (ABC) — all codes implement `encode(bits) → bits` and `decode(bits) → bits` plus expose `code_rate`, `redundancy_ratio`, and `error_correction_capability`.
- **`NoiseModel`** (ABC) — noise models implement `apply(bits) → noisy_bits`. Includes `BinarySymmetricChannel(p)` and `BurstErrorChannel(burst_prob, burst_length)`.
- **`Channel`** — end-to-end pipeline that runs encode → noise → decode and returns a `ChannelResult` with full `Statistics`.
- **`Statistics`** — BER (before/after decoding), bit error counts, code rate, redundancy, encode/decode timing, throughput, and correction effectiveness.
- **`Visualizer`** — static methods for image comparison grids, error heatmaps, BER bar charts, effectiveness charts, timing charts, redundancy charts, and summary tables.

## Quick Start

```bash
# Install dependencies
uv sync

# Run the demo notebook
uv run jupyter notebook notebooks/demo.ipynb
```

### Minimal Python Example

```python
import numpy as np
from ecc.core.message import Message
from ecc.codes.hamming import HammingCode
from ecc.channel.noise import BinarySymmetricChannel
from ecc.channel.channel import Channel

# Create a message from text
msg = Message.from_str("Hello, ECC!")

# Set up channel: Hamming code + 1% bit-flip noise
channel = Channel(
    code=HammingCode(r=3, secded=True),
    noise=BinarySymmetricChannel(p=0.01),
    seed=42,
)

# Transmit
result = channel.transmit(msg.bits)

# Reconstruct and verify
decoded_text = msg.reconstruct(result.decoded_bits)
print(decoded_text)          # "Hello, ECC!"
print(result.stats.summary())  # one-line performance summary
```

### Image Experiment

```python
from PIL import Image
from ecc.codes.reed_solomon import ReedSolomonCode

img = np.array(Image.open("data/images/lenna.png").convert("RGB"), dtype=np.uint8)
msg = Message.from_image(img)

channel = Channel(
    code=ReedSolomonCode(nsym=20),
    noise=BinarySymmetricChannel(p=0.01),
    seed=42,
)
result = channel.transmit(msg.bits)
reconstructed = msg.reconstruct(result.decoded_bits)
```

## Noise Presets

The library includes three built-in presets (importable from `ecc.channel.noise`):

| Preset | Model | Flip Probability |
|--------|-------|-----------------|
| `"small"` | BSC | `p = 0.001` |
| `"medium"` | BSC | `p = 0.01` |
| `"large"` | BSC | `p = 0.05` |

```python
from ecc.channel.noise import NOISE_PRESETS
noise = NOISE_PRESETS["medium"]
```

## Development

```bash
# Lint
uv run ruff check src/

# Format
uv run ruff format src/

# Type check (ty)
uv run ty check src/
```

## Dependencies

- **numpy** — numerical computation
- **matplotlib** — visualization
- **Pillow** — image I/O
- **reedsolo** — Reed-Solomon codec (GF arithmetic)
- **ipykernel** — Jupyter notebook support

Dev: **ruff** (linting + formatting)

## License

MIT
