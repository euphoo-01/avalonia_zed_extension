#!/bin/bash
set -e

# This script automates the build process for the Zed Avalonia extension.
# It compiles the Rust code to wasm32-wasip1, creates the directory
# structure Zed expects (wasm32-wasi), and copies the final binary.

# 1. Build the extension for the wasip1 target
echo "Building extension for wasm32-wasip1..."
cargo build --target wasm32-wasip1

# 2. Ensure the target directory for Zed exists
# Zed currently expects wasm binaries in a 'wasi' subdirectory, not 'wasip1'.
echo "Creating target directory for Zed..."
mkdir -p target/wasm32-wasi/debug

# 3. Copy the compiled .wasm file to the location Zed expects
echo "Copying .wasm binary..."
cp target/wasm32-wasip1/debug/avalonia_zed.wasm target/wasm32-wasi/debug/

echo ""
echo "Build complete!"
echo "The extension binary is now located at: target/wasm32-wasi/debug/avalonia_zed.wasm"
echo "To apply the changes, please reload the Zed editor or the extension."
