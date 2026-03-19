"""Visualization utilities for error-correction experiments."""

from __future__ import annotations

from collections.abc import Sequence
from typing import ClassVar

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.figure import Figure
from numpy.typing import NDArray

from ecc.stats.metrics import Statistics


class Visualizer:
    """Static helper methods for producing publication-quality plots."""

    COLORS: ClassVar[list[str]] = [
        "#2196F3",
        "#FF9800",
        "#4CAF50",
        "#E91E63",
        "#9C27B0",
        "#00BCD4",
    ]
    STYLE_DEFAULTS: ClassVar[dict[str, object]] = {
        "figure.facecolor": "white",
        "axes.grid": True,
        "grid.alpha": 0.3,
        "axes.spines.top": False,
        "axes.spines.right": False,
    }

    @classmethod
    def apply_style(cls) -> None:
        """Apply a clean default matplotlib style."""
        plt.rcParams.update(cls.STYLE_DEFAULTS)

    # --- Image comparison ---

    @staticmethod
    def compare_images(
        original: NDArray[np.uint8],
        reconstructions: dict[str, NDArray[np.uint8]],
        title: str = "Image Reconstruction Comparison",
    ) -> Figure:
        """Show the original image alongside several reconstructions.

        Parameters
        ----------
        original:
            Original image array (HxW or HxWxC).
        reconstructions:
            Mapping ``label -> reconstructed_image``.
        title:
            Super-title for the figure.
        """
        n = 1 + len(reconstructions)
        fig, axes = plt.subplots(1, n, figsize=(4 * n, 4))
        if n == 1:
            axes = [axes]

        cmap = "gray" if original.ndim == 2 else None
        axes[0].imshow(original, cmap=cmap)
        axes[0].set_title("Original")
        axes[0].axis("off")

        for ax, (label, img) in zip(axes[1:], reconstructions.items(), strict=False):
            ax.imshow(img, cmap=cmap)
            ax.set_title(label, fontsize=9)
            ax.axis("off")

        fig.suptitle(title, fontsize=13, fontweight="bold")
        fig.tight_layout()
        return fig

    # --- Error heatmap ---

    @staticmethod
    def error_heatmap(
        original: NDArray[np.uint8],
        reconstructed: NDArray[np.uint8],
        title: str = "Pixel Error Map",
    ) -> Figure:
        """Show per-pixel absolute difference between original and reconstructed images."""
        diff = np.abs(original.astype(np.int16) - reconstructed.astype(np.int16))
        if diff.ndim == 3:
            diff = diff.mean(axis=2)

        fig, ax = plt.subplots(figsize=(6, 5))
        im = ax.imshow(diff, cmap="hot", interpolation="nearest")
        ax.set_title(title)
        ax.axis("off")
        fig.colorbar(im, ax=ax, label="Absolute pixel difference")
        fig.tight_layout()
        return fig

    # --- Statistics bar charts ---

    @staticmethod
    def bar_chart_ber(
        stats_list: Sequence[Statistics],
        title: str = "Bit Error Rate Comparison",
    ) -> Figure:
        """Grouped bar chart of BER before/after decoding for each experiment."""
        labels = [f"{s.code_name}\n{s.noise_name}" for s in stats_list]
        ber_before = [s.ber_before_decode for s in stats_list]
        ber_after = [s.ber_after_decode for s in stats_list]

        x = np.arange(len(labels))
        width = 0.35

        fig, ax = plt.subplots(figsize=(max(8, 2 * len(labels)), 5))
        bars1 = ax.bar(x - width / 2, ber_before, width, label="BER (channel)", color="#FF9800")
        bars2 = ax.bar(x + width / 2, ber_after, width, label="BER (decoded)", color="#4CAF50")

        ax.set_ylabel("Bit Error Rate")
        ax.set_title(title, fontweight="bold")
        ax.set_xticks(x)
        ax.set_xticklabels(labels, fontsize=8)
        ax.legend()
        ax.set_yscale("symlog", linthresh=1e-6)

        # Value labels
        for bars in (bars1, bars2):
            for bar in bars:
                h = bar.get_height()
                if h > 0:
                    ax.annotate(
                        f"{h:.4f}",
                        xy=(bar.get_x() + bar.get_width() / 2, h),
                        xytext=(0, 3),
                        textcoords="offset points",
                        ha="center",
                        va="bottom",
                        fontsize=7,
                    )

        fig.tight_layout()
        return fig

    @staticmethod
    def bar_chart_effectiveness(
        stats_list: Sequence[Statistics],
        title: str = "Error Correction Effectiveness",
    ) -> Figure:
        """Bar chart of correction effectiveness (%) for each experiment."""
        labels = [f"{s.code_name}\n{s.noise_name}" for s in stats_list]
        effectiveness = [s.correction_effectiveness * 100 for s in stats_list]

        fig, ax = plt.subplots(figsize=(max(8, 2 * len(labels)), 5))
        colors = [Visualizer.COLORS[i % len(Visualizer.COLORS)] for i in range(len(labels))]
        bars = ax.bar(labels, effectiveness, color=colors)
        ax.set_ylabel("Correction Effectiveness (%)")
        ax.set_title(title, fontweight="bold")
        ax.set_ylim(0, 105)
        ax.tick_params(axis="x", labelsize=8)

        for bar, val in zip(bars, effectiveness, strict=True):
            ax.annotate(
                f"{val:.1f}%",
                xy=(bar.get_x() + bar.get_width() / 2, val),
                xytext=(0, 3),
                textcoords="offset points",
                ha="center",
                va="bottom",
                fontsize=8,
                fontweight="bold",
            )

        fig.tight_layout()
        return fig

    @staticmethod
    def timing_chart(
        stats_list: Sequence[Statistics],
        title: str = "Encoding / Decoding Time",
    ) -> Figure:
        """Stacked bar chart showing encode + decode times."""
        labels = [f"{s.code_name}\n{s.noise_name}" for s in stats_list]
        enc_times = [s.encode_time_s for s in stats_list]
        dec_times = [s.decode_time_s for s in stats_list]

        x = np.arange(len(labels))
        fig, ax = plt.subplots(figsize=(max(8, 2 * len(labels)), 5))
        ax.bar(x, enc_times, label="Encode", color="#2196F3")
        ax.bar(x, dec_times, bottom=enc_times, label="Decode", color="#E91E63")
        ax.set_ylabel("Time (seconds)")
        ax.set_title(title, fontweight="bold")
        ax.set_xticks(x)
        ax.set_xticklabels(labels, fontsize=8)
        ax.legend()
        fig.tight_layout()
        return fig

    @staticmethod
    def redundancy_chart(
        stats_list: Sequence[Statistics],
        title: str = "Redundancy Overhead",
    ) -> Figure:
        """Bar chart of redundancy ratio and code rate."""
        labels = [s.code_name for s in stats_list]
        # Deduplicate (same code appears multiple times for different noise levels)
        seen: dict[str, Statistics] = {}
        for s in stats_list:
            if s.code_name not in seen:
                seen[s.code_name] = s
        labels = list(seen.keys())
        rates = [seen[lab].code_rate for lab in labels]
        redundancies = [seen[lab].redundancy_ratio * 100 for lab in labels]

        fig, ax1 = plt.subplots(figsize=(max(6, 2 * len(labels)), 5))
        x = np.arange(len(labels))
        width = 0.35

        ax1.bar(x - width / 2, rates, width, label="Code Rate", color="#2196F3")
        ax1.set_ylabel("Code Rate (k/n)")
        ax1.set_ylim(0, 1.1)

        ax2 = ax1.twinx()
        ax2.bar(x + width / 2, redundancies, width, label="Redundancy %", color="#FF9800")
        ax2.set_ylabel("Redundancy Overhead (%)")

        ax1.set_xticks(x)
        ax1.set_xticklabels(labels, fontsize=9)
        ax1.set_title(title, fontweight="bold")

        lines1, labels1 = ax1.get_legend_handles_labels()
        lines2, labels2 = ax2.get_legend_handles_labels()
        ax1.legend(lines1 + lines2, labels1 + labels2, loc="upper right")

        fig.tight_layout()
        return fig

    @staticmethod
    def summary_table(
        stats_list: Sequence[Statistics],
    ) -> Figure:
        """Render a summary table as a matplotlib figure."""
        headers = [
            "Code",
            "Noise",
            "BER (channel)",
            "BER (decoded)",
            "Errors Fixed",
            "Effectiveness",
            "Code Rate",
            "Redundancy",
            "Time (s)",
        ]
        rows = []
        for s in stats_list:
            fixed = s.bit_errors_before - s.bit_errors_after
            rows.append(
                [
                    s.code_name,
                    s.noise_name,
                    f"{s.ber_before_decode:.5f}",
                    f"{s.ber_after_decode:.5f}",
                    f"{fixed}/{s.bit_errors_before}",
                    f"{s.correction_effectiveness:.1%}",
                    f"{s.code_rate:.3f}",
                    f"{s.redundancy_ratio:.1%}",
                    f"{s.encode_time_s + s.decode_time_s:.3f}",
                ]
            )

        fig, ax = plt.subplots(figsize=(16, 0.6 * len(rows) + 1.5))
        ax.axis("off")
        table = ax.table(
            cellText=rows,
            colLabels=headers,
            cellLoc="center",
            loc="center",
        )
        table.auto_set_font_size(False)
        table.set_fontsize(8)
        table.scale(1, 1.4)

        # Style header
        for j in range(len(headers)):
            cell = table[0, j]
            cell.set_facecolor("#37474F")
            cell.set_text_props(color="white", fontweight="bold")

        fig.suptitle("Experiment Summary", fontsize=12, fontweight="bold")
        fig.tight_layout()
        return fig
