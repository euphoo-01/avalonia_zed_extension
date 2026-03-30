use std::fs;
use zed_extension_api::{self as zed, Result};

const GITHUB_REPO: &str = "SaverinOnRails/ls-for-avalonia";

struct AvaloniaExtension {
    cached_binary_path: Option<String>,
}

impl AvaloniaExtension {
    fn get_or_download_languge_server(
        &mut self,
        language_server_id: &zed::LanguageServerId,
    ) -> Result<String> {
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

        let (os, arch) = zed::current_platform();

        let os_name = match os {
            zed::Os::Mac => "macos",
            zed::Os::Linux => "linux",
            zed::Os::Windows => "windows",
        };

        let arch_name = match arch {
            zed::Architecture::X8664 => "x86_64",
            zed::Architecture::Aarch64 => "aarch64",
            _ => return Err(format!("Unsupported architecture: {:?}", arch)),
        };

        let extension = if os == zed::Os::Windows {
            "zip"
        } else {
            "tar.gz"
        };

        let asset_name = format!("avalonia-ls-{}-{}.{}", os_name, arch_name, extension);

        let asset = release
            .assets
            .iter()
            .find(|a| a.name == asset_name)
            .ok_or_else(|| format!("No asset found for platform {}-{}", os_name, arch_name))?;

        let version_dir = format!("avalonia-ls-{}", release.version);
        let binary_name = if os == zed::Os::Windows {
            "AvaloniaLanguageServer.exe"
        } else {
            "AvaloniaLanguageServer"
        };
        let binary_path = format!("{}/{}", version_dir, binary_name);

        if !fs::metadata(&binary_path).is_ok() {
            zed::set_language_server_installation_status(
                language_server_id,
                &zed::LanguageServerInstallationStatus::Downloading,
            );

            let download_type = if os == zed::Os::Windows {
                zed::DownloadedFileType::Zip
            } else {
                zed::DownloadedFileType::GzipTar
            };

            zed::download_file(&asset.download_url, &version_dir, download_type)
                .map_err(|e| format!("Failed to download file: {}", e))?;

            zed::make_file_executable(&binary_path)?;
        }

        self.cached_binary_path = Some(binary_path.clone());
        Ok(binary_path)
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
        if language_server_id.as_ref() == "avalonia-ls" {
            let path = self.get_or_download_languge_server(language_server_id)?;

            Ok(zed::Command {
                command: path,
                args: vec![],
                env: vec![("DOTNET_ROOT".into(), "/usr/share/dotnet".into())],
            })
        } else {
            Err(format!("Unknown language server: {}", language_server_id))
        }
    }
}

zed::register_extension!(AvaloniaExtension);
