# Avalonia UI Extension for Zed

This extension provides language support for Avalonia UI `.axaml` files in the [Zed editor](https://zed.dev/). It enables syntax highlighting and integrates the `avalonia-ls` language server for enhanced code intelligence.

## Features

*   **Syntax Highlighting:** Provides comprehensive highlighting for `.axaml` files, covering standard XML as well as Avalonia-specific syntax such as:
    *   Markup Extensions (`{Binding Path}`, `{StaticResource ...}`)
    *   Style Selectors (`Button.primary:pointerover`)
    *   Control Theme Tags (`<Style>`, `<Setter>`, `<Template>`)
*   **LSP Integration:** Automatically starts and communicates with the `avalonia-ls` language server, enabling features like code completion, diagnostics, and more.

## Language Server

This extension uses the community-maintained language server for Avalonia. For more details on its features and development, please visit its official repository:

*   **[ls-for-avalonia on GitHub](https://github.com/SaverinOnRails/ls-for-avalonia)**

Before using this extension, you must have the language server installed and available in your system's `PATH`.

## Installation

1.  Clone this repository to your local machine.
2.  Move the entire `avalonia-zed` project folder into Zed's local extension directory, which is typically located at `~/.config/zed/extensions/`.
3.  Run the build script to compile the WebAssembly binary:
    ```bash
    ./build.sh
    ```
4.  Restart the Zed editor to load the extension.

## Development

The extension is written in Rust and compiles to WebAssembly.

*   **Prerequisite:** Ensure you have the `wasm32-wasip1` target installed for Rust:
    ```bash
    rustup target add wasm32-wasip1
    ```
*   **Build:** A convenience script is provided to handle the build process and the current `wasip1`/`wasi` path workaround required by Zed. To build the extension, simply run:
    ```bash
    ./build.sh
    ```
This will place the final `avalonia_zed.wasm` binary in the `target/wasm32-wasi/debug/` directory, where Zed expects to find it.
