use zed_extension_api as zed;

struct AvaloniaExtension;

impl zed::Extension for AvaloniaExtension {
    fn new() -> Self {
        Self
    }

    fn language_server_command(
        &mut self,
        language_server_id: &zed::LanguageServerId,
        _worktree: &zed::Worktree,
    ) -> zed::Result<zed::Command> {
        if language_server_id.as_ref() == "avalonia-ls" {
            return Ok(zed::Command {
                command: "avalonia-ls".to_string(),
                args: vec![],
                env: Default::default(),
            });
        }

        Err(format!(
            "Unknown language server: {}",
            language_server_id.as_ref()
        ))
    }
}

zed::register_extension!(AvaloniaExtension);
