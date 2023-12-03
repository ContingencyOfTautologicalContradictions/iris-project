#pragma once
#include "FileOperations.hpp"
#include "WorkspaceEditClientCapabilities.hpp"
#include "ExecuteCommandClientCapabilities.hpp"
#include "WorkspaceSymbolClientCapabilities.hpp"
#include "CodeLensWorkspaceClientCapabilities.hpp"
#include "InlayHintWorkspaceClientCapabilities.hpp"
#include "DiagnosticWorkspaceClientCapabilities.hpp"
#include "InlineValueWorkspaceClientCapabilities.hpp"
#include "DidChangeWatchedFilesClientCapabilities.hpp"
#include "DidChangeConfigurationClientCapabilities.hpp"
#include "SemanticTokensWorkspaceClientCapabilities.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Workspace final
    {
    public:
        Json::Field<bool> applyEdit;

        Json::Field<WorkspaceEditClientCapabilities> workspaceEdit;

        Json::Field<DidChangeConfigurationClientCapabilities>
        didChangeConfiguration;

        Json::Field<DidChangeWatchedFilesClientCapabilities>
        didChangeWatchedFiles;

        Json::Field<WorkspaceSymbolClientCapabilities> symbol;

        Json::Field<ExecuteCommandClientCapabilities> executeCommand;

        Json::Field<bool> workspaceFolders, configuration;

        Json::Field<SemanticTokensWorkspaceClientCapabilities> semanticTokens;

        Json::Field<CodeLensWorkspaceClientCapabilities> codeLens;

        Json::Field<FileOperations> fileOperations;

        Json::Field<InlineValueWorkspaceClientCapabilities> inlineValue;

        Json::Field<InlayHintWorkspaceClientCapabilities> inlayHint;

        Json::Field<DiagnosticWorkspaceClientCapabilities> diagnostics;
    };

    void from_json(const nlohmann::json&, Workspace&);

    void to_json(nlohmann::json&, const Workspace&);
}