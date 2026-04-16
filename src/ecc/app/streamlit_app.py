"""Streamlit interactive demo for Error Correction Codes.

Run with:
    uv run streamlit run src/ecc/app/streamlit_app.py
"""

import sys
import time
import pathlib

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import streamlit as st

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[2]))

from ecc.codes.hamming import HammingCode
from ecc.codes.reed_solomon import ReedSolomonCode
from ecc.codes.polar import PolarCode

# ─────────────────────────────────────────────────────────────
# Page config
# ─────────────────────────────────────────────────────────────
st.set_page_config(
    page_title="Error Correction Codes Demo",
    page_icon="🛡️",
    layout="wide",
)

st.title("🛡️ Error Correction Codes — Interactive Demo")
st.markdown(
    "Encode a random message, inject bit-flip errors, decode with the chosen ECC, "
    "and see exactly which bits were wrong and which were recovered."
)

# ─────────────────────────────────────────────────────────────
# Sidebar controls
# ─────────────────────────────────────────────────────────────
st.sidebar.header("Parameters")

CODE_OPTIONS = {
    "Hamming (r=3, SECDED)": "hamming",
    "Reed-Solomon (nsym=10)": "rs",
    "Polar (n=256, k=128)": "polar",
}
code_label = st.sidebar.selectbox("Error correction code", list(CODE_OPTIONS.keys()))
code_key = CODE_OPTIONS[code_label]

# Powers of 2 starting from 16 (4×4 grid)
MSG_LENGTHS = [16, 32, 64, 128, 256, 512, 1024]
message_length: int = st.sidebar.selectbox("Message length (bits)", MSG_LENGTHS, index=4)

max_errors: int = st.sidebar.slider(
    "Number of random errors (bit flips in message)",
    min_value=0,
    max_value=100,
    value=2,
)

seed: int = int(st.sidebar.number_input("Random seed", min_value=0, max_value=9999, value=1337))

# ─────────────────────────────────────────────────────────────
# Build code object (cached so it isn't recreated on every widget)
# ─────────────────────────────────────────────────────────────
@st.cache_resource
def get_code(key: str) -> object:
    if key == "hamming":
        return HammingCode(r=3, secded=True)
    if key == "rs":
        return ReedSolomonCode(nsym=10)
    return PolarCode(n=256, k=128, max_flips=8)


code = get_code(code_key)

# ─────────────────────────────────────────────────────────────
# Encode → noise → decode
#
# Error injection strategy
# ------------------------
# N flip positions are chosen within the message (0..message_length-1).
#
# • Grid 1 ("without correction"): those exact N positions are flipped in the
#   original message → always exactly N red bits, matching the slider.
#
# • ECC pipeline: the ORIGINAL message is encoded to a clean codeword, then
#   the same N positions are flipped at their corresponding data-bit locations
#   in the encoded stream (not re-encoding a corrupted message, which would
#   produce a valid codeword and give the ECC nothing to fix).
#
# Encoded positions per code
# --------------------------
# Hamming (r=3, SECDED, systematic G=[I_k|P^T]):
#   block size n=8, data bits k=4 per block (data first)
#   message bit i  →  encoded bit (i // k) * n + (i % k)
#
# Reed-Solomon (nsym=10, systematic, data first):
#   all our messages fit in a single RS block (≤ 128 bytes < 245-byte capacity)
#   message bit i  →  encoded bit i   (1:1 direct mapping)
#
# Polar (n=256, k=128, non-systematic after Arikan transform):
#   no simple message→encoded mapping; N random encoded positions are flipped
#   (grid 1 still shows the chosen N message positions as the "uncorrected" view)
# ─────────────────────────────────────────────────────────────
rng = np.random.default_rng(seed)
original = rng.integers(0, 2, size=message_length, dtype=np.uint8)

with st.spinner("Encoding…"):
    t0 = time.perf_counter()
    encoded = code.encode(original)
    t_enc = time.perf_counter() - t0

# Choose flip positions within message bits
n_flips = min(max_errors, message_length)
flip_msg_pos = rng.choice(message_length, size=n_flips, replace=False) if n_flips > 0 else np.array([], dtype=int)

# Grid-1 message: original with those bits flipped (always exactly n_flips red bits)
noisy_msg = original.copy()
noisy_msg[flip_msg_pos] ^= 1

# Build noisy codeword by flipping the corresponding encoded positions
noisy_encoded = encoded.copy()
if n_flips > 0:
    if code_key == "hamming":
        # Hamming(r=3, SECDED): k=4 data bits, n=8 bits per block; data is first k bits
        k_h, n_h = 4, 8
        enc_flip_pos = (flip_msg_pos // k_h) * n_h + (flip_msg_pos % k_h)
    elif code_key == "rs":
        # RS single-block, data-first: message bit i == encoded bit i
        enc_flip_pos = flip_msg_pos.copy()
    else:
        # Polar: non-systematic — inject at random encoded positions
        enc_flip_pos = rng.choice(len(encoded), size=n_flips, replace=False)
    noisy_encoded[enc_flip_pos] ^= 1

with st.spinner("Decoding…"):
    t0 = time.perf_counter()
    decoded = code.decode(noisy_encoded)
    t_dec = time.perf_counter() - t0

decoded = decoded[:message_length]

# ─────────────────────────────────────────────────────────────
# Error maps
#   errors_naive     : positions that differ between original and noisy_msg
#                      (exactly n_flips bits — what you'd see without any ECC)
#   errors_corrected : positions that still differ after ECC decode
#   corrected_bits   : was wrong, now fixed → shown green in grid 2
# ─────────────────────────────────────────────────────────────
errors_naive = (original ^ noisy_msg).astype(bool)
errors_corrected = (original ^ decoded).astype(bool)
corrected_bits = errors_naive & ~errors_corrected

n_err_naive = int(errors_naive.sum())       # always == n_flips
n_err_after = int(errors_corrected.sum())
n_corrected = int(corrected_bits.sum())

# ─────────────────────────────────────────────────────────────
# Metric row
# ─────────────────────────────────────────────────────────────
st.divider()
m1, m2, m3, m4, m5 = st.columns(5)
m1.metric("Encoded length", f"{len(encoded)} bits")
m2.metric("Flips injected", n_flips)
m3.metric("Errors (no ECC)", n_err_naive)
m4.metric(
    "Errors after ECC",
    n_err_after,
    delta=f"{n_err_after - n_err_naive}",
    delta_color="inverse",
)
m5.metric("Bits recovered", n_corrected)

# ─────────────────────────────────────────────────────────────
# Grid helpers
# ─────────────────────────────────────────────────────────────
def _grid_dims(n: int) -> tuple[int, int]:
    """Return (rows, cols) for an n-bit rectangular grid. n must be a power of 2."""
    log2 = int(np.log2(n))
    cols = 2 ** (log2 // 2)
    rows = n // cols
    return rows, cols


def _build_rgb(
    original: np.ndarray,
    error_mask: np.ndarray,
    corrected_mask: np.ndarray | None = None,
    rows: int = 16,
    cols: int = 16,
) -> np.ndarray:
    """
    Build an (rows, cols, 3) float RGB array.

    White  — data bit 1, correct
    Black  — data bit 0, correct
    Red    — wrong bit
    Green  — bit was wrong but recovered by ECC
    """
    img = np.zeros((rows, cols, 3), dtype=np.float32)
    for idx in range(min(len(original), rows * cols)):
        r, c = divmod(idx, cols)
        bit = int(original[idx])
        in_error = bool(error_mask[idx])
        was_corrected = bool(corrected_mask[idx]) if corrected_mask is not None else False

        if in_error:
            img[r, c] = [0.90, 0.15, 0.15]
        elif was_corrected:
            img[r, c] = [0.22, 0.72, 0.22]
        else:
            img[r, c] = [0.93, 0.93, 0.93] if bit else [0.07, 0.07, 0.07]
    return img


def _plot_grid(ax: plt.Axes, img: np.ndarray, title: str, rows: int, cols: int) -> None:
    ax.imshow(img, interpolation="nearest", aspect="equal")
    ax.set_title(title, fontsize=10, fontweight="bold", color="white", pad=8)
    ax.set_xticks([])
    ax.set_yticks([])
    for spine in ax.spines.values():
        spine.set_color("#555555")
    for x in range(cols + 1):
        ax.axvline(x - 0.5, color="#444444", linewidth=0.4)
    for y in range(rows + 1):
        ax.axhline(y - 0.5, color="#444444", linewidth=0.4)


# ─────────────────────────────────────────────────────────────
# Build & render the two grids
# ─────────────────────────────────────────────────────────────
rows, cols = _grid_dims(message_length)

img_noisy = _build_rgb(original, errors_naive, rows=rows, cols=cols)
img_fixed = _build_rgb(original, errors_corrected, corrected_bits, rows=rows, cols=cols)

cell_px = 40  # pixels per bit-cell
fig_w = max(10, cols * cell_px / 72 * 2 + 1)
fig_h = max(5, rows * cell_px / 72 + 1.2)

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(fig_w, fig_h), facecolor="#111111")
fig.subplots_adjust(wspace=0.10, left=0.01, right=0.99, top=0.88, bottom=0.10)
fig.suptitle(
    f"{code_label}  ·  {message_length} message bits  ·  {n_flips} injected flips",
    fontsize=12, color="white", fontweight="bold",
)

_plot_grid(ax1, img_noisy, f"Without correction  ({n_err_naive} wrong bits)", rows, cols)
_plot_grid(ax2, img_fixed, f"After ECC  ({n_err_after} wrong  ·  {n_corrected} recovered)", rows, cols)

legend_handles = [
    mpatches.Patch(facecolor=(0.93, 0.93, 0.93), edgecolor="#555", label="Correct  (bit = 1)"),
    mpatches.Patch(facecolor=(0.07, 0.07, 0.07), edgecolor="#555", label="Correct  (bit = 0)"),
    mpatches.Patch(facecolor=(0.90, 0.15, 0.15), edgecolor="#555", label="Error  (wrong bit)"),
    mpatches.Patch(facecolor=(0.22, 0.72, 0.22), edgecolor="#555", label="Recovered by ECC"),
]
fig.legend(
    handles=legend_handles,
    loc="lower center",
    ncol=4,
    fontsize=9,
    facecolor="#222222",
    edgecolor="#666666",
    labelcolor="white",
    bbox_to_anchor=(0.5, 0.00),
)

st.pyplot(fig, use_container_width=True)
plt.close(fig)

# ─────────────────────────────────────────────────────────────
# Timing footer
# ─────────────────────────────────────────────────────────────
st.caption(
    f"⏱ Encode: {t_enc * 1000:.1f} ms  ·  Decode: {t_dec * 1000:.1f} ms  ·  "
    f"Code rate: {message_length / len(encoded):.3f}  ·  "
    f"Overhead: {(len(encoded) - message_length) / message_length * 100:.1f}%"
)

# ─────────────────────────────────────────────────────────────
# Explanation expander
# ─────────────────────────────────────────────────────────────
with st.expander("How to read this visualization"):
    st.markdown(
        """
**Left grid — Without correction:**
The original message with exactly the chosen number of bit flips applied at
message level. Each red cell is one wrong bit — the count always matches the
slider.

**Right grid — After ECC:**
The same N bit errors are injected at their true positions in the *encoded*
codeword (not the message), then the ECC decoder corrects them. Green cells
were wrong and got **recovered**; red cells couldn't be fixed.

| Colour | Meaning |
|--------|---------|
| ⬜ White | Bit is 1, correct |
| ⬛ Black | Bit is 0, correct |
| 🟥 Red | Wrong bit |
| 🟩 Green | Was wrong, recovered by ECC |

**Grid size** is always `rows × cols = message_length`, reshaped to the nearest
power-of-2 rectangle (e.g. 256 bits → 16×16, 128 bits → 8×16, 16 bits → 4×4).
"""
    )
