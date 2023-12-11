#include "ServerCapabilities.hpp"

namespace Iris::LSP
{
    [[nodiscard]] auto Registration(const nlohmann::json& data) noexcept ->
    bool
    {
        return data.contains("documentSelector") or data.contains("id");
    }

    void from_json(const nlohmann::json& data, ServerCapabilities& sc)
    {
        sc.positionEncoding = Json::Field<PositionEncodingKind>(data,
        "positionEncoding");
        if(data.contains("textDocumentSync"))
        {
            sc.textDocumentSync.Set();
            const nlohmann::json& textDocumentSync = data.at("textDocumentSync"
            );
            if(textDocumentSync.is_number())
                sc.textDocumentSync.Value() = textDocumentSync.get<
                TextDocumentSyncKind>();
            else
                sc.textDocumentSync.Value() = textDocumentSync.get<
                TextDocumentSyncOptions>();
        }
        if(data.contains("notebookDocumentSync"))
        {
            sc.notebookDocumentSync.Set();
            const nlohmann::json& notebookDocumentSync = data.at(
            "notebookDocumentSync");
            if(notebookDocumentSync.contains("id"))
                sc.notebookDocumentSync.Value() = notebookDocumentSync.get<
                NotebookDocumentSyncRegistrationOptions>();
            else
                sc.notebookDocumentSync.Value() = notebookDocumentSync.get<
                NotebookDocumentSyncOptions>();
        }
        sc.completionProvider = Json::Field<CompletionOptions>(data,
        "completionProvider");
        if(data.contains("hoverProvider"))
        {
            sc.hoverProvider.Set();
            const nlohmann::json& hoverProvider = data.at("hoverProvider");
            if(hoverProvider.is_boolean())
                sc.hoverProvider.Value() = hoverProvider.get<bool>();
            else
                sc.hoverProvider.Value() = hoverProvider.get<HoverOptions>();
        }
        sc.signatureHelpProvider = Json::Field<SignatureHelpOptions>(data,
        "signatureHelpProvider");
        if(data.contains("declarationProvider"))
        {
            sc.declarationProvider.Set();
            const nlohmann::json& declarationProvider = data.at(
            "declarationProvider");
            if(declarationProvider.is_boolean())
                sc.declarationProvider.Value() = declarationProvider.get<bool>(
                );
            else if(Registration(declarationProvider))
                sc.declarationProvider.Value() = declarationProvider.get<
                DeclarationRegistrationOptions>();
            else
                sc.declarationProvider.Value() = declarationProvider.get<
                DeclarationOptions>();
        }
        if(data.contains("definitionProvider"))
        {
            sc.definitionProvider.Set();
            const nlohmann::json& definitionProvider = data.at(
            "definitionProvider");
            if(definitionProvider.is_boolean())
                sc.definitionProvider.Value() = definitionProvider.get<bool>();
            else
                sc.definitionProvider.Value() = definitionProvider.get<
                DefinitionOptions>();
        }
        if(data.contains("typeDefinitionProvider"))
        {
            sc.typeDefinitionProvider.Set();
            const nlohmann::json& typeDefinitionProvider = data.at(
            "typeDefinitionProvider");
            if(typeDefinitionProvider.is_boolean())
                sc.typeDefinitionProvider.Value() = typeDefinitionProvider.get<
                bool>();
            else if(Registration(typeDefinitionProvider))
                sc.typeDefinitionProvider.Value() = typeDefinitionProvider.get<
                TypeDefinitionRegistrationOptions>();
            else
                sc.typeDefinitionProvider.Value() = typeDefinitionProvider.get<
                TypeDefinitionOptions>();
        }
        if(data.contains("implementationProvider"))
        {
            sc.implementationProvider.Set();
            const nlohmann::json& implementationProvider = data.at(
            "implementationProvider");
            if(implementationProvider.is_boolean())
                sc.implementationProvider.Value() = implementationProvider.get<
                bool>();
            else if(Registration(implementationProvider))
                sc.implementationProvider.Value() = implementationProvider.get<
                ImplementationRegistrationOptions>();
            else
                sc.implementationProvider.Value() = implementationProvider.get<
                ImplementationOptions>();
        }
        if(data.contains("referencesProvider"))
        {
            sc.referencesProvider.Set();
            const nlohmann::json& referencesProvider = data.at(
            "referencesProvider");
            if(referencesProvider.is_boolean())
                sc.referencesProvider.Value() = referencesProvider.get<bool>();
            else
                sc.referencesProvider.Value() = referencesProvider.get<
                ReferenceOptions>();
        }
        if(data.contains("documentHighlightProvider"))
        {
            sc.documentHighlightProvider.Set();
            const nlohmann::json& documentHighlightProvider = data.at(
            "documentHighlightOptions");
            if(documentHighlightProvider.is_boolean())
                sc.documentHighlightProvider.Value() =
                documentHighlightProvider.get<bool>();
            else
                sc.documentHighlightProvider.Value() =
                documentHighlightProvider.get<DocumentHighlightOptions>();
        }
        if(data.contains("documentSymbolProvider"))
        {
            sc.documentSymbolProvider.Set();
            const nlohmann::json& documentSymbolProvider = data.at(
            "documentSymbolProvider");
            if(documentSymbolProvider.is_boolean())
                sc.documentSymbolProvider.Value() = documentSymbolProvider.get<
                bool>();
            else
                sc.documentSymbolProvider.Value() = documentSymbolProvider.get<
                DocumentSymbolOptions>();
        }
        if(data.contains("codeActionProvider"))
        {
            sc.codeActionProvider.Set();
            const nlohmann::json& codeActionProvider = data.at(
            "codeActionProvider");
            if(codeActionProvider.is_boolean())
                sc.codeActionProvider.Value() = codeActionProvider.get<bool>();
            else
                sc.codeActionProvider.Value() = codeActionProvider.get<
                CodeActionOptions>();
        }
        sc.codeLensProvider = Json::Field<CodeLensOptions>(data,
        "codeLensProvider");
        sc.documentLinkProvider = Json::Field<DocumentLinkOptions>(data,
        "documentLinkProvider");
        if(data.contains("colorProvider"))
        {
            sc.colorProvider.Set();
            const nlohmann::json& colorProvider = data.at("colorProvider");
            if(colorProvider.is_boolean())
                sc.colorProvider.Value() = colorProvider.get<bool>();
            else if(Registration(colorProvider))
                sc.colorProvider.Value() = colorProvider.get<
                DocumentColorRegistrationOptions>();
            else
                sc.colorProvider.Value() = colorProvider.get<
                DocumentColorOptions>();
        }
        if(data.contains("documentFormattingProvider"))
        {
            sc.documentFormattingProvider.Set();
            const nlohmann::json& documentFormattingProvider = data.at(
            "documentFormattingProvider");
            if(documentFormattingProvider.is_boolean())
                sc.documentFormattingProvider.Value() =
                documentFormattingProvider.get<bool>();
            else
                sc.documentFormattingProvider.Value() =
                documentFormattingProvider.get<DocumentFormattingOptions>();
        }
        if(data.contains("documentRangeFormattingOptions"))
        {
            sc.documentRangeFormattingProvider.Set();
            const nlohmann::json& documentRangeFormattingProvider = data.at(
            "documentRangeFormattingProvider");
            if(documentRangeFormattingProvider.is_boolean())
                sc.documentRangeFormattingProvider.Value() =
                documentRangeFormattingProvider.get<bool>();
            else
                sc.documentRangeFormattingProvider.Value() =
                documentRangeFormattingProvider.get<
                DocumentRangeFormattingOptions>();
        }
        sc.documentOnTypeFormattingProvider = Json::Field<
        DocumentOnTypeFormattingOptions>(data,
        "documentOnTypeFormattingOptions");
        if(data.contains("renameProvider"))
        {
            sc.renameProvider.Set();
            const nlohmann::json& renameProvider = data.at("renameProvider");
            if(renameProvider.is_boolean())
                sc.renameProvider.Value() = renameProvider.get<bool>();
            else
                sc.renameProvider.Value() = renameProvider.get<RenameOptions>()
                ;
        }
        if(data.contains("foldingRangeProvider"))
        {
            sc.foldingRangeProvider.Set();
            const nlohmann::json& foldingRangeProvider = data.at(
            "foldingRangeProvider");
            if(foldingRangeProvider.is_boolean())
                sc.foldingRangeProvider.Value() = foldingRangeProvider.get<bool
                >();
            else if(Registration(foldingRangeProvider))
                sc.foldingRangeProvider.Value() = foldingRangeProvider.get<
                FoldingRangeRegistrationOptions>();
            else
                sc.foldingRangeProvider.Value() = foldingRangeProvider.get<
                FoldingRangeOptions>();
        }
        sc.executeCommandProvider = Json::Field<ExecuteCommandOptions>(data,
        "executeCommandProvider");
        if(data.contains("selectionRangeProvider"))
        {
            sc.selectionRangeProvider.Set();
            const nlohmann::json& selectionRangeProvider = data.at(
            "selectionRangeProvider");
            if(selectionRangeProvider.is_boolean())
                sc.selectionRangeProvider.Value() = selectionRangeProvider.get<
                bool>();
            else if(Registration(selectionRangeProvider))
                sc.selectionRangeProvider.Value() = selectionRangeProvider.get<
                SelectionRangeRegistrationOptions>();
            else
                sc.selectionRangeProvider.Value() = selectionRangeProvider.get<
                SelectionRangeOptions>();
        }
        if(data.contains("linkedEditingRangeProvider"))
        {
            sc.linkedEditingRangeProvider.Set();
            const nlohmann::json& linkedEditingRangeProvider = data.at(
            "linkedEditingRangeProvider");
            if(linkedEditingRangeProvider.is_boolean())
                sc.linkedEditingRangeProvider.Value() =
                linkedEditingRangeProvider.get<bool>();
            else if(Registration(linkedEditingRangeProvider))
                sc.linkedEditingRangeProvider.Value() =
                linkedEditingRangeProvider.get<
                LinkedEditingRangeRepresentationOptions>();
            else
                sc.linkedEditingRangeProvider.Value() =
                linkedEditingRangeProvider.get<LinkedEditingRangeOptions>();
        }
        if(data.contains("callHierarchyProvider"))
        {
            sc.callHierarchyProvider.Set();
            const nlohmann::json& callHierarchyProvider = data.at(
            "callHierarchyProvider");
            if(callHierarchyProvider.is_boolean())
                sc.callHierarchyProvider.Value() = callHierarchyProvider.get<
                bool>();
            else if(Registration(callHierarchyProvider))
                sc.callHierarchyProvider.Value() = callHierarchyProvider.get<
                CallHierarchyRegistrationOptions>();
            else
                sc.callHierarchyProvider.Value() = callHierarchyProvider.get<
                CallHierarchyOptions>();
        }
        if(data.contains("semanticTokensProvider"))
        {
            sc.semanticTokensProvider.Set();
            const nlohmann::json& semanticTokensProvider = data.at(
            "semanticTokensProvider");
            if(Registration(semanticTokensProvider))
                sc.semanticTokensProvider.Value() = semanticTokensProvider.get<
                SemanticTokensRegistrationOptions>();
            else
                sc.semanticTokensProvider.Value() = semanticTokensProvider.get<
                SemanticTokensOptions>();
        }
        if(data.contains("monikerProvider"))
        {
            sc.monikerProvider.Set();
            const nlohmann::json& monikerProvider = data.at("monikerProvider");
            if(monikerProvider.is_boolean())
                sc.monikerProvider.Value() = monikerProvider.get<bool>();
            else if(Registration(monikerProvider))
                sc.monikerProvider.Value() = monikerProvider.get<MonikerOptions
                >();
            else
                sc.monikerProvider.Value() = monikerProvider.get<
                MonikerRegistrationOptions>();
        }
        if(data.contains("typeHierarchyProvider"))
        {
            sc.typeHierarchyProvider.Set();
            const nlohmann::json& typeHierarchyProvider = data.at(
            "typeHierarchyProvider");
            if(typeHierarchyProvider.is_boolean())
                sc.typeHierarchyProvider.Value() = typeHierarchyProvider.get<
                bool>();
            else if(Registration(typeHierarchyProvider))
                sc.typeHierarchyProvider.Value() = typeHierarchyProvider.get<
                TypeHierarchyRegistrationOptions>();
            else
                sc.typeHierarchyProvider.Value() = typeHierarchyProvider.get<
                TypeHierarchyOptions>();
        }
        if(data.contains("inlineValueProvider"))
        {
            sc.inlineValueProvider.Set();
            const nlohmann::json& inlineValueProvider = data.at(
            "inlineValueProvider");
            if(inlineValueProvider.is_boolean())
                sc.inlineValueProvider.Value() = inlineValueProvider.get<bool>(
                );
            else if(Registration(inlineValueProvider))
                sc.inlineValueProvider.Value() = inlineValueProvider.get<
                InlineValueRegistrationOptions>();
            else
                sc.inlineValueProvider.Value() = inlineValueProvider.get<
                InlineValueOptions>();
        }
        if(data.contains("inlayHintProvider"))
        {
            sc.inlayHintProvider.Set();
            const nlohmann::json& inlayHintProvider = data.at(
            "inlayHintProvider");
            if(inlayHintProvider.is_boolean())
                sc.inlayHintProvider.Value() = inlayHintProvider.get<bool>();
            else if(Registration(inlayHintProvider))
                sc.inlayHintProvider.Value() = inlayHintProvider.get<
                InlayHintRegistrationOptions>();
            else
                sc.inlayHintProvider.Value() = inlayHintProvider.get<
                InlayHintOptions>();
        }
        if(data.contains("diagnosticProvider"))
        {
            sc.diagnosticProvider.Set();
            const nlohmann::json& diagnosticProvider = data.at(
            "diagnosticProvider");
            if(Registration(diagnosticProvider))
                sc.diagnosticProvider.Value() = diagnosticProvider.get<
                DiagnosticRegistrationOptions>();
            else
                sc.diagnosticProvider.Value() = diagnosticProvider.get<
                DiagnosticOptions>();
        }
        if(data.contains("workspaceSymbolProvider"))
        {
            sc.workspaceSymbolProvider.Set();
            const nlohmann::json& workspaceSymbolProvider = data.at(
            "workspaceSymbolProvider");
            if(workspaceSymbolProvider.is_boolean())
                sc.workspaceSymbolProvider.Value() = workspaceSymbolProvider.
                get<bool>();
            else
                sc.workspaceSymbolProvider.Value() = workspaceSymbolProvider.
                get<WorkspaceSymbolOptions>();
        }
        sc.workspace = Json::Field<Workspace2>(data, "workspace");
    }

    void to_json(nlohmann::json& data, const ServerCapabilities& sc)
    {
        if(sc.positionEncoding.Present())
            data["positionEncoding"] = sc.positionEncoding.Value();
        if(sc.textDocumentSync.Present())
            std::visit([&](auto&& active)
            {
                data["textDocumentSync"] = active;
            }, sc.textDocumentSync.Value());
        if(sc.notebookDocumentSync.Present())
            std::visit([&](auto&& active)
            {
                data["notebookDocumentSync"] = active;
            }, sc.notebookDocumentSync.Value());
        if(sc.completionProvider.Present())
            data["completionProvider"] = sc.completionProvider.Value();
        if(sc.hoverProvider.Present())
            std::visit([&](auto&& active)
            {
                data["hoverProvider"] = active;
            }, sc.hoverProvider.Value());
        if(sc.signatureHelpProvider.Present())
            data["signatureHelpProvider"] = sc.signatureHelpProvider.Value();
        if(sc.declarationProvider.Present())
            std::visit([&](auto&& active)
            {
                data["declarationProvider"] = active;
            }, sc.declarationProvider.Value());
        if(sc.definitionProvider.Present())
            std::visit([&](auto&& active)
            {
                data["definitionProvider"] = active;
            }, sc.definitionProvider.Value());
        if(sc.typeDefinitionProvider.Present())
            std::visit([&](auto&& active)
            {
                data["typeDefinitionProvider"] = active;
            }, sc.typeDefinitionProvider.Value());
        if(sc.implementationProvider.Present())
            std::visit([&](auto&& active)
            {
                data["implementationProvider"] = active;
            }, sc.implementationProvider.Value());
        if(sc.referencesProvider.Present())
            std::visit([&](auto&& active)
            {
                data["referencesProvider"] = active;
            }, sc.referencesProvider.Value());
        if(sc.documentHighlightProvider.Present())
            std::visit([&](auto&& active)
            {
                data["documentHighlightProvider"] = active;
            }, sc.documentHighlightProvider.Value());
        if(sc.documentSymbolProvider.Present())
            std::visit([&](auto&& active)
            {
                data["documentSymbolProvider"] = active;
            }, sc.documentSymbolProvider.Value());
        if(sc.codeActionProvider.Present())
            std::visit([&](auto&& active)
            {
                data["codeActionProvider"] = active;
            }, sc.codeActionProvider.Value());
        if(sc.codeLensProvider.Present())
            data["codeLensProvider"] = sc.codeLensProvider.Value();
        if(sc.documentLinkProvider.Present())
            data["documentLinkProvider"] = sc.documentLinkProvider.Value();
        if(sc.colorProvider.Present())
            std::visit([&](auto&& active)
            {
                data["colorProvider"] = active;
            }, sc.colorProvider.Value());
        if(sc.documentFormattingProvider.Present())
            std::visit([&](auto&& active)
            {
                data["documentFormattingProvider"] = active;
            }, sc.documentFormattingProvider.Value());
        if(sc.documentRangeFormattingProvider.Present())
            std::visit([&](auto&& active)
            {
                data["documentRangeFormattingProvider"] = active;
            }, sc.documentRangeFormattingProvider.Value());
        if(sc.documentOnTypeFormattingProvider.Present())
            data["documentOnTypeFormattingProvider"] = sc.
            documentOnTypeFormattingProvider.Value();
        if(sc.renameProvider.Present())
            std::visit([&](auto&& active)
            {
                data["renameProvider"] = active;
            }, sc.renameProvider.Value());
        if(sc.foldingRangeProvider.Present())
            std::visit([&](auto&& active)
            {
                data["foldingRangeProvider"] = active;
            }, sc.foldingRangeProvider.Value());
        if(sc.executeCommandProvider.Present())
            data["executeCommandProvider"] = sc.executeCommandProvider.Value();
        if(sc.selectionRangeProvider.Present())
            std::visit([&](auto&& active)
            {
                data["selectionRangeProvider"] = active;
            }, sc.selectionRangeProvider.Value());
        if(sc.linkedEditingRangeProvider.Present())
            std::visit([&](auto&& active)
            {
                data["linkedEditingRangeProvider"] = active;
            }, sc.linkedEditingRangeProvider.Value());
        if(sc.callHierarchyProvider.Present())
            std::visit([&](auto&& active)
            {
                data["callHierarchyProvider"] = active;
            }, sc.callHierarchyProvider.Value());
        if(sc.semanticTokensProvider.Present())
            std::visit([&](auto&& active)
            {
                data["semanticTokensProvider"] = active;
            }, sc.semanticTokensProvider.Value());
        if(sc.monikerProvider.Present())
            std::visit([&](auto&& active)
            {
                data["monikerProvider"] = active;
            }, sc.monikerProvider.Value());
        if(sc.typeHierarchyProvider.Present())
            std::visit([&](auto&& active)
            {
                data["typeHierarchyProvider"] = active;
            }, sc.typeHierarchyProvider.Value());
        if(sc.inlineValueProvider.Present())
            std::visit([&](auto&& active)
            {
                data["inlineValueProvider"] = active;
            }, sc.inlineValueProvider.Value());
        if(sc.inlayHintProvider.Present())
            std::visit([&](auto&& active)
            {
                data["inlayHintProvider"] = active;
            }, sc.inlayHintProvider.Value());
        if(sc.diagnosticProvider.Present())
            std::visit([&](auto&& active)
            {
                data["diagnosticProvider"] = active;
            }, sc.diagnosticProvider.Value());
        if(sc.workspaceSymbolProvider.Present())
            std::visit([&](auto&& active)
            {
                data["workspaceSymbolProvider"] = active;
            }, sc.workspaceSymbolProvider.Value());
        if(sc.workspace.Present())
            data["workspace"] = sc.workspace.Value();
    }
}