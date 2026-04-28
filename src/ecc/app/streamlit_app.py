"""Streamlit interactive demo for Error Correction Codes.

Run with:
    uv run streamlit run src/ecc/app/streamlit_app.py
"""

import pathlib
import sys
import time

import matplotlib.patches as mpatches
import matplotlib.pyplot as plt
import numpy as np
import streamlit as st

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[2]))

from ecc.codes.hamming import HammingCode
from ecc.codes.polar import PolarCode
from ecc.codes.reed_solomon import ReedSolomonCode


st.set_page_config(
    page_title="Error Correction Codes Demo",
    page_icon="🛡️",
    layout="wide",
)

st.markdown(
    """
    <style>
    div[data-testid="column"] div.stButton > button {
        min-height: 2.35rem;
        padding: 0.2rem 0.15rem;
        font-family: ui-monospace, SFMono-Regular, Menlo, Monaco, Consolas, "Liberation Mono", monospace;
        font-size: 0.78rem;
        border-radius: 0.2rem;
    }
    </style>
    """,
    unsafe_allow_html=True,
)


CODE_OPTIONS = {
    "Hamming (r=3, SECDED)": "hamming",
    "Reed-Solomon (nsym=10)": "rs",
    "Polar (n=256, k=128)": "polar",
}

MSG_LENGTHS = [16, 32, 64, 128, 256, 512, 1024]
MAX_INTERACTIVE_COLS = 16
HAMMING_VISUAL_CONTROL_POSITIONS = {0, 1, 3, 7}
HAMMING_VISUAL_BLOCK_SIZE = 16


@st.cache_resource
def get_code(key: str) -> object:
    if key == "hamming":
        return HammingCode(r=3, secded=True)
    if key == "rs":
        return ReedSolomonCode(nsym=10)
    return PolarCode(n=256, k=128, max_flips=8)


def _grid_dims(n: int, max_cols: int | None = None) -> tuple[int, int]:
    if n <= 0:
        return 0, 0
    cols = int(np.ceil(np.sqrt(n)))
    if max_cols is not None:
        cols = min(cols, max_cols)
    rows = int(np.ceil(n / cols))
    return rows, cols


def _pad_for_grid(values: np.ndarray, rows: int, cols: int, fill: int = 0) -> np.ndarray:
    padded = np.full(rows * cols, fill, dtype=values.dtype)
    padded[: len(values)] = values
    return padded.reshape(rows, cols)


def _hamming_data_positions(code: HammingCode) -> list[int]:
    return [i for i in range(code.n) if not code._is_power_of_two(i + 1)]


def _hamming_control_mask(code: HammingCode, n_bits: int) -> np.ndarray:
    mask = np.zeros(n_bits, dtype=bool)
    for start in range(0, n_bits, code._total_n):
        end = min(start + code._total_n, n_bits)
        for pos in range(code.n):
            if start + pos < end and code._is_power_of_two(pos + 1):
                mask[start + pos] = True
        if code.secded and start + code.n < end:
            mask[start + code.n] = True
    return mask


def _rs_control_mask(code: ReedSolomonCode, n_bits: int) -> np.ndarray:
    mask = np.zeros(n_bits, dtype=bool)
    block_bits = code._n_symbols * 8
    parity_bits = code.nsym * 8
    for start in range(0, n_bits, block_bits):
        end = min(start + block_bits, n_bits)
        parity_start = max(start, end - parity_bits)
        mask[parity_start:end] = True
    return mask


def _polar_control_mask(code: PolarCode, n_bits: int) -> np.ndarray:
    mask = np.zeros(n_bits, dtype=bool)
    block_n = code._n
    for start in range(0, n_bits, block_n):
        end = min(start + block_n, n_bits)
        block_len = end - start
        mask[start:end] = code._frozen_mask[:block_len]
    return mask


def _control_mask(code_key: str, code: object, n_bits: int) -> np.ndarray:
    if code_key == "hamming":
        return _hamming_control_mask(code, n_bits)
    if code_key == "rs":
        return _rs_control_mask(code, n_bits)
    return _polar_control_mask(code, n_bits)


def _visual_control_mask(code_key: str, n_bits: int) -> np.ndarray:
    mask = np.zeros(n_bits, dtype=bool)
    if code_key == "hamming":
        for start in range(0, n_bits, HAMMING_VISUAL_BLOCK_SIZE):
            for offset in HAMMING_VISUAL_CONTROL_POSITIONS:
                idx = start + offset
                if idx < n_bits:
                    mask[idx] = True
    return mask


def _message_to_encoded_positions(code_key: str, code: object, msg_positions: np.ndarray) -> np.ndarray:
    if len(msg_positions) == 0:
        return np.array([], dtype=int)
    if code_key == "hamming":
        data_positions = np.array(_hamming_data_positions(code), dtype=int)
        block = msg_positions // code.k
        offset = msg_positions % code.k
        return block * code._total_n + data_positions[offset]
    if code_key == "rs":
        return msg_positions.copy()
    return np.array([], dtype=int)


def _visual_to_encoded_position(code_key: str, code: object, visual_idx: int, encoded_len: int) -> int:
    visual_offset = visual_idx % HAMMING_VISUAL_BLOCK_SIZE
    if code_key == "hamming" and visual_offset in HAMMING_VISUAL_CONTROL_POSITIONS:
        parity_offsets = [0, 1, 3, code.n]
        parity_idx = sorted(HAMMING_VISUAL_CONTROL_POSITIONS).index(visual_offset)
        block_group = visual_idx // HAMMING_VISUAL_BLOCK_SIZE
        block_idx = block_group * len(HAMMING_VISUAL_CONTROL_POSITIONS) + parity_idx
        block_idx = min(block_idx, max(encoded_len // code._total_n - 1, 0))
        return min(block_idx * code._total_n + parity_offsets[parity_idx], encoded_len - 1)
    mapped = _message_to_encoded_positions(code_key, code, np.array([visual_idx], dtype=int))
    if len(mapped) == 0:
        return min(visual_idx, encoded_len - 1)
    return min(int(mapped[0]), encoded_len - 1)


def _visual_received_bits(
    code_key: str,
    code: object,
    encoded: np.ndarray,
    received: np.ndarray,
    received_payload: np.ndarray,
    n_bits: int,
) -> tuple[np.ndarray, np.ndarray]:
    visual_bits = received_payload.copy()
    visual_errors = np.zeros(n_bits, dtype=bool)
    for idx in range(n_bits):
        encoded_idx = _visual_to_encoded_position(code_key, code, idx, len(encoded))
        visual_errors[idx] = encoded[encoded_idx] != received[encoded_idx]
        if idx % HAMMING_VISUAL_BLOCK_SIZE in HAMMING_VISUAL_CONTROL_POSITIONS and code_key == "hamming":
            visual_bits[idx] = received[encoded_idx]
    return visual_bits, visual_errors


def _visual_bits_from_codeword(
    code_key: str,
    code: object,
    encoded: np.ndarray,
    payload: np.ndarray,
    n_bits: int,
) -> np.ndarray:
    visual_bits = payload.copy()
    if code_key != "hamming":
        return visual_bits
    for idx in range(n_bits):
        if idx % HAMMING_VISUAL_BLOCK_SIZE in HAMMING_VISUAL_CONTROL_POSITIONS:
            encoded_idx = _visual_to_encoded_position(code_key, code, idx, len(encoded))
            visual_bits[idx] = encoded[encoded_idx]
    return visual_bits


def _raw_payload_from_received(
    code_key: str,
    code: object,
    received: np.ndarray,
    message_length: int,
) -> tuple[np.ndarray, str]:
    if code_key == "hamming":
        received = code._pad_to_multiple(received, code._total_n)
        blocks = received.reshape(-1, code._total_n)
        bits = [code._extract_data_bits(block[: code.n]) for block in blocks]
        return np.concatenate(bits).astype(np.uint8)[:message_length], "received data bits"
    if code_key == "rs":
        return received[:message_length].astype(np.uint8), "received data bits"
    return received[:message_length].astype(np.uint8), "received codeword prefix"


def _hamming_syndrome_rows(code: HammingCode, received: np.ndarray) -> list[dict[str, object]]:
    padded = code._pad_to_multiple(received, code._total_n)
    rows = []
    for block_idx, block in enumerate(padded.reshape(-1, code._total_n)):
        inner = block[: code.n].copy()
        syndrome = (code._H @ inner) % 2
        syndrome_val = 0
        for i, bit in enumerate(syndrome):
            syndrome_val |= int(bit) << (code.r - 1 - i)
        overall = int(np.sum(block)) % 2 if code.secded else None
        if syndrome_val == 0 and overall == 0:
            status = "clean"
        elif syndrome_val == 0 and overall == 1:
            status = "overall parity bit error"
        elif overall == 1 or not code.secded:
            status = f"correctable bit {syndrome_val}"
        else:
            status = "detected double error"
        rows.append(
            {
                "block": block_idx,
                "syndrome": "".join(str(int(x)) for x in syndrome),
                "value": syndrome_val,
                "overall parity": "-" if overall is None else overall,
                "status": status,
            }
        )
    return rows


def _rs_syndrome_rows(code: ReedSolomonCode, received: np.ndarray) -> list[dict[str, object]]:
    from reedsolo import rs_calc_syndromes

    byte_data = code._bits_to_bytes(received)
    rows = []
    for block_idx, start in enumerate(range(0, len(byte_data), code._n_symbols)):
        block = byte_data[start : start + code._n_symbols]
        if len(block) <= code.nsym:
            rows.append(
                {
                    "block": block_idx,
                    "syndrome": "-",
                    "nonzero syndromes": "-",
                    "status": "too short",
                }
            )
            continue
        syndromes = rs_calc_syndromes(block, code.nsym)
        syndrome_body = syndromes[1:] if len(syndromes) == code.nsym + 1 else syndromes
        nonzero = sum(1 for value in syndrome_body if value != 0)
        try:
            code._codec.decode(block)
            status = "clean" if nonzero == 0 else "correctable"
        except Exception:
            status = "uncorrectable"
        rows.append(
            {
                "block": block_idx,
                "syndrome": " ".join(f"{value:02x}" for value in syndrome_body),
                "nonzero syndromes": nonzero,
                "status": status,
            }
        )
    return rows


def _polar_syndrome_rows(code: PolarCode, received: np.ndarray) -> list[dict[str, object]]:
    rows = []
    mag = code._llr_magnitude
    padded = code._pad_to_multiple(received, code._n)
    for block_idx, block in enumerate(padded.reshape(-1, code._n)):
        llr = np.where(block == 0, mag, -mag)
        u_hat = code._sc_decode(llr)
        frozen_violations = int(np.sum(u_hat[code._frozen_mask] != 0))
        rows.append(
            {
                "block": block_idx,
                "frozen-bit violations": frozen_violations,
                "status": "constraint check",
            }
        )
    return rows


def _syndrome_table(code_key: str, code: object, received: np.ndarray) -> tuple[list[dict[str, object]], str]:
    if code_key == "hamming":
        return _hamming_syndrome_rows(code, received), "Hamming syndrome"
    if code_key == "rs":
        return _rs_syndrome_rows(code, received), "Reed-Solomon decoder status"
    return _polar_syndrome_rows(code, received), "Polar frozen-constraint check"


def _build_stage_rgb(
    bits: np.ndarray,
    wrong_mask: np.ndarray,
    recovered_mask: np.ndarray | None,
    rows: int,
    cols: int,
) -> np.ndarray:
    img = np.full((rows * cols, 3), [0.13, 0.15, 0.17], dtype=np.float32)
    recovered_mask = np.zeros(len(bits), dtype=bool) if recovered_mask is None else recovered_mask
    for idx, bit in enumerate(bits):
        if wrong_mask[idx]:
            img[idx] = [0.92, 0.18, 0.18]
        elif recovered_mask[idx]:
            img[idx] = [0.15, 0.68, 0.36]
        else:
            img[idx] = [0.94, 0.94, 0.90] if int(bit) else [0.05, 0.06, 0.07]
    return img.reshape(rows, cols, 3)


def _build_message_rgb(
    bits: np.ndarray,
    control_mask: np.ndarray,
    wrong_mask: np.ndarray,
    recovered_mask: np.ndarray | None,
    rows: int,
    cols: int,
) -> np.ndarray:
    img = np.full((rows * cols, 3), [0.13, 0.15, 0.17], dtype=np.float32)
    recovered_mask = np.zeros(len(bits), dtype=bool) if recovered_mask is None else recovered_mask
    for idx, bit in enumerate(bits):
        if wrong_mask[idx]:
            img[idx] = [0.92, 0.18, 0.18]
        elif recovered_mask[idx]:
            img[idx] = [0.15, 0.68, 0.36]
        elif control_mask[idx]:
            img[idx] = [0.20, 0.47, 0.90] if int(bit) else [0.09, 0.22, 0.45]
        else:
            img[idx] = [0.94, 0.94, 0.90] if int(bit) else [0.05, 0.06, 0.07]
    return img.reshape(rows, cols, 3)


def _draw_grid(ax: plt.Axes, img: np.ndarray, title: str, rows: int, cols: int) -> None:
    ax.imshow(img, interpolation="nearest", aspect="equal")
    ax.set_title(title, fontsize=10, fontweight="bold", color="white", pad=8)
    ax.set_xticks([])
    ax.set_yticks([])
    for spine in ax.spines.values():
        spine.set_color("#555555")
    for x in range(cols + 1):
        ax.axvline(x - 0.5, color="#454545", linewidth=0.35)
    for y in range(rows + 1):
        ax.axhline(y - 0.5, color="#454545", linewidth=0.35)


def _plot_message_matrix(
    bits: np.ndarray,
    title: str,
    control_mask: np.ndarray | None = None,
    wrong_mask: np.ndarray | None = None,
    recovered_mask: np.ndarray | None = None,
    show_control_legend: bool = False,
) -> plt.Figure:
    rows, cols = _grid_dims(len(bits))
    if control_mask is None:
        control_mask = np.zeros(len(bits), dtype=bool)
    if wrong_mask is None:
        wrong_mask = np.zeros(len(bits), dtype=bool)
    image = _build_message_rgb(bits, control_mask, wrong_mask, recovered_mask, rows, cols)
    fig_w = max(3.6, cols * 0.48)
    fig_h = max(3.6 if show_control_legend else 3.0, rows * 0.48 + 1.1)
    fig, ax = plt.subplots(1, 1, figsize=(fig_w, fig_h), facecolor="#111111")
    fig.subplots_adjust(left=0.01, right=0.99, top=0.82, bottom=0.18 if show_control_legend else 0.03)
    _draw_grid(ax, image, title, rows, cols)
    if show_control_legend:
        handles = [
            mpatches.Patch(facecolor=(0.94, 0.94, 0.90), edgecolor="#555", label="Data 1"),
            mpatches.Patch(facecolor=(0.05, 0.06, 0.07), edgecolor="#555", label="Data 0"),
            mpatches.Patch(facecolor=(0.20, 0.47, 0.90), edgecolor="#555", label="Control 1"),
            mpatches.Patch(facecolor=(0.09, 0.22, 0.45), edgecolor="#555", label="Control 0"),
        ]
        fig.legend(
            handles=handles,
            loc="lower center",
            ncol=2,
            fontsize=7,
            facecolor="#222222",
            edgecolor="#666666",
            labelcolor="white",
        )
    return fig


def _plot_correction_matrix(
    decoded: np.ndarray,
    recovered_mask: np.ndarray,
    uncorrected_mask: np.ndarray,
) -> plt.Figure:
    rows, cols = _grid_dims(len(decoded))
    control_mask = np.zeros(len(decoded), dtype=bool)
    image = _build_message_rgb(decoded, control_mask, uncorrected_mask, recovered_mask, rows, cols)
    fig_w = max(3.6, cols * 0.48)
    fig_h = max(3.6, rows * 0.48 + 1.1)
    fig, ax = plt.subplots(1, 1, figsize=(fig_w, fig_h), facecolor="#111111")
    fig.subplots_adjust(left=0.01, right=0.99, top=0.82, bottom=0.16)
    _draw_grid(ax, image, "Correction result", rows, cols)
    handles = [
        mpatches.Patch(facecolor=(0.15, 0.68, 0.36), edgecolor="#555", label="Corrected"),
        mpatches.Patch(facecolor=(0.92, 0.18, 0.18), edgecolor="#555", label="Still wrong"),
        mpatches.Patch(facecolor=(0.94, 0.94, 0.90), edgecolor="#555", label="Correct 1"),
        mpatches.Patch(facecolor=(0.05, 0.06, 0.07), edgecolor="#555", label="Correct 0"),
    ]
    fig.legend(
        handles=handles,
        loc="lower center",
        ncol=2,
        fontsize=8,
        facecolor="#222222",
        edgecolor="#666666",
        labelcolor="white",
    )
    return fig


def _plot_mini_matrix(
    bits: np.ndarray,
    title: str,
    control_mask: np.ndarray | None = None,
    wrong_mask: np.ndarray | None = None,
    recovered_mask: np.ndarray | None = None,
) -> plt.Figure:
    rows, cols = _grid_dims(len(bits))
    if control_mask is None:
        control_mask = np.zeros(len(bits), dtype=bool)
    if wrong_mask is None:
        wrong_mask = np.zeros(len(bits), dtype=bool)
    image = _build_message_rgb(bits, control_mask, wrong_mask, recovered_mask, rows, cols)
    fig, ax = plt.subplots(1, 1, figsize=(2.2, 2.35), facecolor="#111111")
    fig.subplots_adjust(left=0.02, right=0.98, top=0.78, bottom=0.04)
    _draw_grid(ax, image, title, rows, cols)
    return fig


def _bits_as_groups(bits: np.ndarray, group_size: int = 4) -> str:
    text = "".join(str(int(bit)) for bit in bits)
    return " ".join(text[i : i + group_size] for i in range(0, len(text), group_size))


def _flip_report_rows(
    code_key: str,
    code: object,
    encoded: np.ndarray,
    received: np.ndarray,
    visual_bits: np.ndarray,
    visual_control_mask: np.ndarray,
    visual_error_mask: np.ndarray,
) -> list[dict[str, object]]:
    rows = []
    for idx, changed in enumerate(visual_error_mask):
        if not changed:
            continue
        encoded_idx = _visual_to_encoded_position(code_key, code, idx, len(encoded))
        rows.append(
            {
                "matrix cell": idx + 1,
                "role": "control" if visual_control_mask[idx] else "data",
                "encoded bit": encoded_idx + 1,
                "before": int(encoded[encoded_idx]),
                "sent": int(received[encoded_idx]),
                "shown as": int(visual_bits[idx]),
            }
        )
    return rows


def _render_interactive_matrix(
    code_key: str,
    code: object,
    encoded: np.ndarray,
    visual_bits: np.ndarray,
    visual_control_mask: np.ndarray,
    visual_error_mask: np.ndarray,
    run_id: str,
) -> None:
    rows, cols = _grid_dims(len(visual_bits), max_cols=MAX_INTERACTIVE_COLS)
    st.markdown("**2. Add channel errors**")
    st.caption("Click cells to flip bits in the matrix. `C` marks the Hamming control positions.")
    for row in range(rows):
        columns = st.columns(cols, gap="small")
        for col in range(cols):
            idx = row * cols + col
            with columns[col]:
                if idx >= len(visual_bits):
                    st.write("")
                    continue
                role = "C" if visual_control_mask[idx] else "D"
                prefix = "E" if visual_error_mask[idx] else role
                label = f"{prefix}{int(visual_bits[idx])}"
                help_text = f"Matrix bit {idx + 1}: {'control' if visual_control_mask[idx] else 'data'}"
                if st.button(label, key=f"flip:{run_id}:{idx}", help=help_text, use_container_width=True):
                    encoded_idx = _visual_to_encoded_position(code_key, code, idx, len(encoded))
                    st.session_state["received_bits"][encoded_idx] ^= 1
                    st.rerun()


st.title("Error Correction Codes")
st.markdown(
    "Encode a message, perturb the transmitted codeword, and watch the decoder "
    "move from original bits through channel errors to the repaired payload."
)

st.sidebar.header("Parameters")
code_label = st.sidebar.selectbox("Error correction code", list(CODE_OPTIONS.keys()))
code_key = CODE_OPTIONS[code_label]
message_length = int(st.sidebar.selectbox("Message length (bits)", MSG_LENGTHS, index=0))
random_errors = int(
    st.sidebar.slider(
        "Random message-bit flips",
        min_value=0,
        max_value=100,
        value=0,
    )
)
seed = int(st.sidebar.number_input("Random seed", min_value=0, max_value=9999, value=1337))

code = get_code(code_key)
run_id = f"{code_key}:{message_length}:{seed}:{random_errors}"

rng = np.random.default_rng(seed)
original = rng.integers(0, 2, size=message_length, dtype=np.uint8)

with st.spinner("Encoding..."):
    t0 = time.perf_counter()
    encoded = code.encode(original)
    t_enc = time.perf_counter() - t0

if st.session_state.get("run_id") != run_id:
    n_flips = min(random_errors, message_length)
    flip_visual_pos = (
        rng.choice(message_length, size=n_flips, replace=False)
        if n_flips > 0
        else np.array([], dtype=int)
    )
    encoded_flips = np.array(
        [
            _visual_to_encoded_position(code_key, code, int(pos), len(encoded))
            for pos in flip_visual_pos
        ],
        dtype=int,
    )
    if code_key == "polar" and n_flips > 0:
        encoded_flips = rng.choice(len(encoded), size=n_flips, replace=False)
    received = encoded.copy()
    received[encoded_flips] ^= 1
    st.session_state["run_id"] = run_id
    st.session_state["received_bits"] = received

received_bits = np.array(st.session_state["received_bits"], dtype=np.uint8)
visual_control_mask = _visual_control_mask(code_key, message_length)

with st.spinner("Decoding..."):
    t0 = time.perf_counter()
    decoded = code.decode(received_bits)[:message_length]
    t_dec = time.perf_counter() - t0

received_payload, payload_label = _raw_payload_from_received(
    code_key, code, received_bits, message_length
)
received_payload = received_payload[:message_length]
visual_original_bits = _visual_bits_from_codeword(
    code_key,
    code,
    encoded,
    original,
    message_length,
)
visual_received_bits, visual_error_mask = _visual_received_bits(
    code_key,
    code,
    encoded,
    received_bits,
    received_payload,
    message_length,
)

channel_flips = encoded != received_bits
message_errors_before = original != received_payload
message_errors_after = original != decoded
recovered_bits = message_errors_before & ~message_errors_after
control_flip_mask = visual_control_mask & visual_error_mask
control_corrected_mask = control_flip_mask & ~message_errors_after.any()
control_uncorrected_mask = control_flip_mask & message_errors_after.any()
correction_recovered_mask = recovered_bits | control_corrected_mask
correction_uncorrected_mask = message_errors_after | control_uncorrected_mask
flip_report = _flip_report_rows(
    code_key,
    code,
    encoded,
    received_bits,
    visual_received_bits,
    visual_control_mask,
    visual_error_mask,
)

m1, m2, m3, m4, m5, m6 = st.columns(6)
m1.metric("Encoded length", f"{len(encoded)} bits")
m2.metric("Channel flips", int(channel_flips.sum()))
m3.metric("Control flips", int(control_flip_mask.sum()))
m4.metric("Data errors before", int(message_errors_before.sum()))
m5.metric(
    "Errors after ECC",
    int(message_errors_after.sum()),
    delta=int(message_errors_after.sum()) - int(message_errors_before.sum()),
    delta_color="inverse",
)
m6.metric("Data bits recovered", int(recovered_bits.sum()))

st.divider()
st.subheader("Message flow")

panel1, panel2, panel3, panel4 = st.columns(4)

with panel1:
    st.markdown("**1. Original message**")
    original_fig = _plot_message_matrix(
        visual_original_bits,
        "Original bits",
        control_mask=visual_control_mask,
        show_control_legend=True,
    )
    st.pyplot(original_fig, use_container_width=True)
    plt.close(original_fig)

with panel2:
    _render_interactive_matrix(
        code_key,
        code,
        encoded,
        visual_received_bits,
        visual_control_mask,
        visual_error_mask,
        run_id,
    )
    b1, b2 = st.columns(2)
    with b1:
        if st.button("Reset", key=f"reset:{run_id}", use_container_width=True):
            st.session_state.pop("run_id", None)
            st.rerun()
    with b2:
        if st.button("Clear", key=f"clear:{run_id}", use_container_width=True):
            st.session_state["received_bits"] = encoded.copy()
            st.rerun()

with panel3:
    st.markdown("**3. Sent before correction**")
    sent_fig = _plot_message_matrix(
        visual_received_bits,
        "Received bits",
    )
    st.pyplot(sent_fig, use_container_width=True)
    plt.close(sent_fig)
    st.caption(f"{int(visual_error_mask.sum())} flipped cells before decoding")

with panel4:
    st.markdown("**4. Current decoded bits**")
    decoded_fig = _plot_message_matrix(decoded, "Decoded bits")
    st.pyplot(decoded_fig, use_container_width=True)
    plt.close(decoded_fig)
    st.caption(_bits_as_groups(decoded))
    st.caption(f"{int(message_errors_after.sum())} wrong after decoding")

st.markdown("**Corrected results**")
result_left, result_mid, result_right = st.columns([1, 2, 1])
with result_mid:
    correction_fig = _plot_correction_matrix(
        decoded,
        correction_recovered_mask,
        correction_uncorrected_mask,
    )
    st.pyplot(correction_fig, use_container_width=True)
    plt.close(correction_fig)
    st.caption(
        f"Data fixes: {int(recovered_bits.sum())} | "
        f"Control-position flips handled: {int(control_corrected_mask.sum())} | "
        f"Still wrong: {int(correction_uncorrected_mask.sum())}"
    )

if flip_report:
    with st.expander("Channel flip report", expanded=True):
        st.dataframe(flip_report, use_container_width=True, hide_index=True)

st.markdown("**Pipeline progression**")
pipe_cols = st.columns([1, 0.18, 1, 0.18, 1, 0.18, 1, 0.18, 1])
pipeline_items = [
    (
        0,
        "Original",
        visual_original_bits,
        visual_control_mask,
        np.zeros(message_length, dtype=bool),
        None,
    ),
    (
        2,
        "Noise",
        visual_received_bits,
        np.zeros(message_length, dtype=bool),
        visual_error_mask,
        None,
    ),
    (
        4,
        "Sent",
        visual_received_bits,
        np.zeros(message_length, dtype=bool),
        np.zeros(message_length, dtype=bool),
        None,
    ),
    (
        6,
        "Decoded",
        decoded,
        np.zeros(message_length, dtype=bool),
        np.zeros(message_length, dtype=bool),
        None,
    ),
    (
        8,
        "Result",
        decoded,
        np.zeros(message_length, dtype=bool),
        correction_uncorrected_mask,
        correction_recovered_mask,
    ),
]
for col_idx, title, bits, controls, wrong, recovered in pipeline_items:
    with pipe_cols[col_idx]:
        fig = _plot_mini_matrix(bits, title, controls, wrong, recovered)
        st.pyplot(fig, use_container_width=True)
        plt.close(fig)
        st.code(_bits_as_groups(bits), language="text")

for arrow_idx in [1, 3, 5, 7]:
    with pipe_cols[arrow_idx]:
        st.markdown("<div style='text-align:center; padding-top:4.5rem; font-size:1.6rem;'>→</div>", unsafe_allow_html=True)

syndrome_df, syndrome_title = _syndrome_table(code_key, code, received_bits)
st.subheader(syndrome_title)
st.dataframe(syndrome_df, use_container_width=True, hide_index=True)

st.caption(
    f"Encode: {t_enc * 1000:.1f} ms  |  Decode: {t_dec * 1000:.1f} ms  |  "
    f"Code rate: {message_length / len(encoded):.3f}  |  "
    f"Overhead: {(len(encoded) - message_length) / message_length * 100:.1f}%"
)

with st.expander("How to read this visualization"):
    st.markdown(
        """
The top row uses the same message-space matrix: original bits, clickable
channel-error insertion, sent bits before correction, and current decoded bits.
The sent-before-correction matrix is intentionally neutral and shows only the
bit values. The pipeline includes a separate Noise step that highlights which
cells were flipped. The corrected-results matrix underneath marks repaired
message bits and corrected control-position flips in green, and still-wrong
cells in red.

For the Hamming view, every 16-bit visual block highlights four teaching
control positions, 1, 2, 4, and 8. The real implementation underneath is
Hamming(r=3) SECDED, so a 16-bit payload is encoded as four Hamming(8,4)
blocks and each block can correct one single-bit error. That is why multiple
fixed bits are possible when the errors fall in different blocks. In the
interactive matrix, `D` marks data, `C` marks those visual control positions,
and `E` marks a currently flipped cell.

The syndrome section reports the decoder-side consistency check. Hamming shows
the actual binary syndrome per block; Reed-Solomon shows syndrome bytes and
correction status; Polar reports frozen-bit constraint violations from a plain
successive-cancellation pass.
"""
    )
