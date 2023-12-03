#include "Workspace.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Workspace& w)
    {
        w.applyEdit = Json::Field<bool>(data, "applyEdit");
        w.workspaceEdit = Json::Field<WorkspaceEditClientCapabilities>(data,
        "workspaceEdit");
        w.didChangeConfiguration = Json::Field<
        DidChangeConfigurationClientCapabilities>(data,
        "didChangeConfiguration");
        w.didChangeWatchedFiles = Json::Field<
        DidChangeWatchedFilesClientCapabilities>(data, "didChangeWatchedFiles")
        ;
        w.symbol = Json::Field<WorkspaceSymbolClientCapabilities>(data,
        "symbol");
        w.executeCommand = Json::Field<ExecuteCommandClientCapabilities>(data,
        "executeCommand");
        w.workspaceFolders = Json::Field<bool>(data, "workspaceFolders");
        w.configuration = Json::Field<bool>(data, "configuration");
        w.semanticTokens = Json::Field<
        SemanticTokensWorkspaceClientCapabilities>(data, "semanticTokens");
        w.codeLens = Json::Field<CodeLensWorkspaceClientCapabilities>(data,
        "codeLens");
        w.fileOperations = Json::Field<FileOperations>(data, "fileOperations");
        w.inlineValue = Json::Field<InlineValueWorkspaceClientCapabilities>(
        data, "inlineValue");
        w.inlayHint = Json::Field<InlayHintWorkspaceClientCapabilities>(data,
        "inlayHint");
        w.diagnostics = Json::Field<DiagnosticWorkspaceClientCapabilities>(data
        , "diagnostics");
    }

    void to_json(nlohmann::json& data, const Workspace& w)
    {
        if(w.applyEdit.Present())
            data["applyEdit"] = w.applyEdit.Value();
        if(w.workspaceEdit.Present())
            data["workspaceEdit"] = w.workspaceEdit.Value();
        if(w.didChangeConfiguration.Present())
            data["didChangeConfiguration"] = w.didChangeConfiguration.Value();
        if(w.didChangeWatchedFiles.Present())
            data["didChangeWatchedFiles"] = w.didChangeWatchedFiles.Value();
        if(w.symbol.Present())
            data["symbol"] = w.symbol.Value();
        if(w.executeCommand.Present())
            data["executeCommand"] = w.executeCommand.Value();
        if(w.workspaceFolders.Present())
            data["workspaceFolders"] = w.workspaceFolders.Value();
        if(w.configuration.Present())
            data["configuration"] = w.configuration.Value();
        if(w.semanticTokens.Present())
            data["semanticTokens"] = w.semanticTokens.Value();
        if(w.codeLens.Present())
            data["codeLens"] = w.codeLens.Value();
        if(w.fileOperations.Present())
            data["fileOperations"] = w.fileOperations.Value();
        if(w.inlineValue.Present())
            data["inlineValue"] = w.inlineValue.Value();
        if(w.inlayHint.Present())
            data["inlayHint"] = w.inlayHint.Value();
        if(w.diagnostics.Present())
            data["diagnostics"] = w.diagnostics.Value();
    }
}