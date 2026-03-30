#!/bin/bash
set -e

# Build the Tree-sitter grammar
pushd grammars/avalonia
echo "--- Building Tree-sitter grammar ---"
npm install
npx tree-sitter generate
popd

# Build the Rust Wasm extension
echo "--- Building Rust Wasm extension ---"
cargo build --target wasm32-wasip1 --release

# Zed's local dev extension loader looks for `extension.wasm` in the root folder.
# We also keep it in the `target` folder to follow standard build patterns.
echo "--- Copying extension.wasm to project root for local testing ---"
cp target/wasm32-wasip1/release/avalonia_zed.wasm ./extension.wasm

echo "--- Build complete! ---"
echo "The extension artifact is ready at: ./extension.wasm"
