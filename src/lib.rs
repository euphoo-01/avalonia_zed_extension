use std::fs;
use std::path::{Path, PathBuf};

use zed_extension_api::{self as zed, DownloadedFileType, Result};

const GITHUB_REPO: &str = "euphoo-01/ls_for_avalonia";
const LANGUAGE_SERVER_ID: &str = "avalonia-ls";
const LOCAL_BINARY_OVERRIDE_ENV: &str = "AVALONIA_LS_BINARY";

struct AvaloniaExtension {
    cached_binary_path: Option<String>,
}

struct ReleaseAssetSpec {
    asset_name: &'static str,
    binary_name: &'static str,
    downloaded_file_type: DownloadedFileType,
}

impl AvaloniaExtension {
    fn language_server_binary_path(
        &mut self,
        language_server_id: &zed::LanguageServerId,
    ) -> Result<String> {
        if let Some(path) = Self::local_binary_override()? {
            self.cached_binary_path = Some(path.clone());
            return Ok(path);
        }

        if let Some(path) = &self.cached_binary_path {
            if fs::metadata(path).is_ok() {
                return Ok(path.clone());
            }
        }

        zed::set_language_server_installation_status(
            language_server_id,
            &zed::LanguageServerInstallationStatus::CheckingForUpdate,
        );

        let release = zed::latest_github_release(
            GITHUB_REPO,
            zed::GithubReleaseOptions {
                require_assets: true,
                pre_release: false,
            },
        )?;

        let spec = Self::release_asset_spec()?;
        let asset = release
            .assets
            .iter()
            .find(|asset| asset.name == spec.asset_name)
            .ok_or_else(|| {
                format!(
                    "Release {} for {} is missing the expected asset {}",
                    release.version, GITHUB_REPO, spec.asset_name
                )
            })?;

        let version_dir = format!("{}-{}", LANGUAGE_SERVER_ID, release.version);
        let binary_path = Self::find_binary_path(&version_dir, spec.binary_name);

        let binary_path = match binary_path {
            Some(binary_path) => binary_path,
            None => {
                zed::set_language_server_installation_status(
                    language_server_id,
                    &zed::LanguageServerInstallationStatus::Downloading,
                );

                zed::download_file(&asset.download_url, &version_dir, spec.downloaded_file_type)
                    .map_err(|error| {
                        format!(
                            "Failed to download {} from {}: {}",
                            spec.asset_name, GITHUB_REPO, error
                        )
                    })?;

                Self::find_binary_path(&version_dir, spec.binary_name).ok_or_else(|| {
                    format!(
                        "Downloaded {} but could not find {} under {}",
                        spec.asset_name, spec.binary_name, version_dir
                    )
                })?
            }
        };

        if !binary_path.ends_with(".exe") {
            zed::make_file_executable(&binary_path)?;
        }

        self.cached_binary_path = Some(binary_path.clone());
        Ok(binary_path)
    }

    fn local_binary_override() -> Result<Option<String>> {
        match std::env::var(LOCAL_BINARY_OVERRIDE_ENV) {
            Ok(path) => {
                let metadata = fs::metadata(&path).map_err(|error| {
                    format!(
                        "{} is set to {:?}, but the file is not readable: {}",
                        LOCAL_BINARY_OVERRIDE_ENV, path, error
                    )
                })?;

                if metadata.is_file() {
                    Ok(Some(path))
                } else {
                    Err(format!(
                        "{} is set to {:?}, but it is not a file",
                        LOCAL_BINARY_OVERRIDE_ENV, path
                    ))
                }
            }
            Err(std::env::VarError::NotPresent) => Ok(None),
            Err(std::env::VarError::NotUnicode(_)) => Err(format!(
                "{} is set but is not valid UTF-8",
                LOCAL_BINARY_OVERRIDE_ENV
            )),
        }
    }

    fn release_asset_spec() -> Result<ReleaseAssetSpec> {
        let (os, arch) = zed::current_platform();

        match (os, arch) {
            (zed::Os::Linux, zed::Architecture::X8664) => Ok(ReleaseAssetSpec {
                asset_name: "avalonia-ls-linux-x86_64.tar.gz",
                binary_name: "AvaloniaLanguageServer",
                downloaded_file_type: DownloadedFileType::GzipTar,
            }),
            (zed::Os::Linux, zed::Architecture::Aarch64) => Ok(ReleaseAssetSpec {
                asset_name: "avalonia-ls-linux-aarch64.tar.gz",
                binary_name: "AvaloniaLanguageServer",
                downloaded_file_type: DownloadedFileType::GzipTar,
            }),
            (zed::Os::Mac, zed::Architecture::X8664) => Ok(ReleaseAssetSpec {
                asset_name: "avalonia-ls-macos-x86_64.tar.gz",
                binary_name: "AvaloniaLanguageServer",
                downloaded_file_type: DownloadedFileType::GzipTar,
            }),
            (zed::Os::Mac, zed::Architecture::Aarch64) => Ok(ReleaseAssetSpec {
                asset_name: "avalonia-ls-macos-aarch64.tar.gz",
                binary_name: "AvaloniaLanguageServer",
                downloaded_file_type: DownloadedFileType::GzipTar,
            }),
            (zed::Os::Windows, zed::Architecture::X8664) => Ok(ReleaseAssetSpec {
                asset_name: "avalonia-ls-windows-x86_64.zip",
                binary_name: "AvaloniaLanguageServer.exe",
                downloaded_file_type: DownloadedFileType::Zip,
            }),
            (zed::Os::Windows, zed::Architecture::X86) => Err(
                "Windows x86 is not supported by euphoo-01/ls_for_avalonia release assets"
                    .to_string(),
            ),
            (zed::Os::Windows, zed::Architecture::Aarch64) => Err(
                "Windows aarch64 is not supported by euphoo-01/ls_for_avalonia release assets"
                    .to_string(),
            ),
            (zed::Os::Mac, zed::Architecture::X86) => {
                Err("macOS x86 is not supported by Zed's extension host".to_string())
            }
            (zed::Os::Linux, zed::Architecture::X86) => Err(
                "Linux x86 is not supported by euphoo-01/ls_for_avalonia release assets"
                    .to_string(),
            ),
        }
    }

    fn find_binary_path(version_dir: &str, binary_name: &str) -> Option<String> {
        let root = Path::new(version_dir);
        if !root.exists() {
            return None;
        }

        Self::find_binary_path_recursive(root, binary_name)
            .map(|path| path.to_string_lossy().into())
    }

    fn find_binary_path_recursive(root: &Path, binary_name: &str) -> Option<PathBuf> {
        let entries = fs::read_dir(root).ok()?;

        for entry in entries {
            let entry = entry.ok()?;
            let path = entry.path();

            if path.is_file()
                && path.file_name().and_then(|name| name.to_str()) == Some(binary_name)
            {
                return Some(path);
            }

            if path.is_dir() {
                if let Some(binary_path) = Self::find_binary_path_recursive(&path, binary_name) {
                    return Some(binary_path);
                }
            }
        }

        None
    }
}

impl zed::Extension for AvaloniaExtension {
    fn new() -> Self {
        Self {
            cached_binary_path: None,
        }
    }

    fn language_server_command(
        &mut self,
        language_server_id: &zed::LanguageServerId,
        _worktree: &zed::Worktree,
    ) -> Result<zed::Command> {
        if language_server_id.as_ref() != LANGUAGE_SERVER_ID {
            return Err(format!("Unknown language server: {}", language_server_id));
        }

        let command = self.language_server_binary_path(language_server_id)?;
        Ok(zed::Command {
            command,
            args: vec!["--stdio".to_string()],
            env: vec![],
        })
    }
}

zed::register_extension!(AvaloniaExtension);
