#!/bin/bash
set -e

pushd grammars/avalonia

echo "--- Building Tree-sitter grammar ---"
npm install
npx tree-sitter generate

popd

echo "--- Building Rust Wasm extension ---"
cargo build --target wasm32-wasip1 --release

echo "--- Moving .wasm artifact to expected location ---"
mkdir -p target/wasm32-wasi/release
cp target/wasm32-wasip1/release/avalonia_zed.wasm target/wasm32-wasi/release/

echo "--- Build complete! ---"
echo "The extension artifact is located at: target/wasm32-wasi/release/avalonia_zed.wasm"
