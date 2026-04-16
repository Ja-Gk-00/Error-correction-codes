"""Launch the ECC Streamlit app."""

import subprocess
import sys
import pathlib

app = pathlib.Path(__file__).parent / "src" / "ecc" / "app" / "streamlit_app.py"
subprocess.run([sys.executable, "-m", "streamlit", "run", str(app)], check=True)
