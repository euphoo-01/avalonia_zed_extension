#!/bin/bash
set -e

# Build the Rust Wasm extension
echo "--- Building Rust Wasm extension ---"
cargo build --target wasm32-wasip2 --release

# Zed's local dev extension loader looks for `extension.wasm` in the root folder.
# We also keep it in the `target` folder to follow standard build patterns.
echo "--- Copying extension.wasm to project root for local testing ---"
cp target/wasm32-wasip2/release/avalonia_zed.wasm ./extension.wasm

echo "--- Build complete! ---"
echo "The extension artifact is ready at: ./extension.wasm"
