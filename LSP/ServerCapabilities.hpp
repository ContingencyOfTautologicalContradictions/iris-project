#pragma once
#include "Workspace2.hpp"
#include "HoverOptions.hpp"
#include "RenameOptions.hpp"
#include "MonikerOptions.hpp"
#include "CodeLensOptions.hpp"
#include "ReferenceOptions.hpp"
#include "InlayHintOptions.hpp"
#include "CompletionOptions.hpp"
#include "DefinitionOptions.hpp"
#include "CodeActionOptions.hpp"
#include "DiagnosticOptions.hpp"
#include "DeclarationOptions.hpp"
#include "InlineValueOptions.hpp"
#include "DocumentLinkOptions.hpp"
#include "FoldingRangeOptions.hpp"
#include "PositionEncodingKind.hpp"
#include "SignatureHelpOptions.hpp"
#include "DocumentColorOptions.hpp"
#include "CallHierarchyOptions.hpp"
#include "TypeHierarchyOptions.hpp"
#include "TypeDefinitionOptions.hpp"
#include "ImplementationOptions.hpp"
#include "DocumentSymbolOptions.hpp"
#include "ExecuteCommandOptions.hpp"
#include "SelectionRangeOptions.hpp"
#include "SemanticTokensOptions.hpp"
#include "WorkspaceSymbolOptions.hpp"
#include "TextDocumentSyncOptions.hpp"
#include "DocumentHighlightOptions.hpp"
#include "DocumentFormattingOptions.hpp"
#include "LinkedEditingRangeOptions.hpp"
#include "MonikerRegistrationOptions.hpp"
#include "NotebookDocumentSyncOptions.hpp"
#include "InlayHintRegistrationOptions.hpp"
#include "DiagnosticRegistratonOptions.hpp"
#include "DeclarationRegistrationOptions.hpp"
#include "DocumentRangeFormattingOptions.hpp"
#include "InlineValueRegistrationOptions.hpp"
#include "FoldingRangeRegistrationOptions.hpp"
#include "DocumentOnTypeFormattingOptions.hpp"
#include "DocumentColorRegistrationOptions.hpp"
#include "CallHierarchyRegistrationOptions.hpp"
#include "TypeHierarchyRegistrationOptions.hpp"
#include "TypeDefinitionRegistrationOptions.hpp"
#include "ImplementationRegistrationOptions.hpp"
#include "SelectionRangeRegistrationOptions.hpp"
#include "SemanticTokensRegistrationOptions.hpp"
#include "LinkedEditingRangeRegistrationOptions.hpp"
#include "NotebookDocumentSyncRegistrationOptions.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ServerCapabilities final
    {
    public:
        Json::Field<PositionEncodingKind> positionEncoding;

        Json::Field<std::variant<TextDocumentSyncKind, TextDocumentSyncOptions>
        > textDocumentSync;

        Json::Field<std::variant<NotebookDocumentSyncOptions,
        NotebookDocumentSyncRegistrationOptions>> notebookDocumentSync;

        Json::Field<CompletionOptions> completionProvider;

        Json::Field<std::variant<bool, HoverOptions>> hoverProvider;

        Json::Field<SignatureHelpOptions> signatureHelpProvider;

        Json::Field<std::variant<bool, DeclarationOptions,
        DeclarationRegistrationOptions>> declarationProvider;

        Json::Field<std::variant<bool, DefinitionOptions>> definitionProvider;

        Json::Field<std::variant<bool, TypeDefinitionOptions,
        TypeDefinitionRegistrationOptions>> typeDefinitionProvider;

        Json::Field<std::variant<bool, ImplementationOptions,
        ImplementationRegistrationOptions>> implementationProvider;

        Json::Field<std::variant<bool, ReferenceOptions>> referencesProvider;

        Json::Field<std::variant<bool, DocumentHighlightOptions>>
        documentHighlightProvider;

        Json::Field<std::variant<bool, DocumentSymbolOptions>>
        documentSymbolProvider;

        Json::Field<std::variant<bool, CodeActionOptions>> codeActionProvider;

        Json::Field<CodeLensOptions> codeLensProvider;

        Json::Field<DocumentLinkOptions> documentLinkProvider;

        Json::Field<std::variant<bool, DocumentColorOptions,
        DocumentColorRegistrationOptions>> colorProvider;

        Json::Field<std::variant<bool, DocumentFormattingOptions>>
        documentFormattingProvider;

        Json::Field<std::variant<bool, DocumentRangeFormattingOptions>>
        documentRangeFormattingProvider;

        Json::Field<DocumentOnTypeFormattingOptions>
        documentOnTypeFormattingProvider;

        Json::Field<std::variant<bool, RenameOptions>> renameProvider;

        Json::Field<std::variant<bool, FoldingRangeOptions,
        FoldingRangeRegistrationOptions>> foldingRangeProvider;

        Json::Field<ExecuteCommandOptions> executeCommandProvider;

        Json::Field<std::variant<bool, SelectionRangeOptions,
        SelectionRangeRegistrationOptions>> selectionRangeProvider;

        Json::Field<std::variant<bool, LinkedEditingRangeOptions,
        LinkedEditingRangeRepresentationOptions>> linkedEditingRangeProvider;

        Json::Field<std::variant<bool, CallHierarchyOptions,
        CallHierarchyRegistrationOptions>> callHierarchyProvider;

        Json::Field<std::variant<SemanticTokensOptions,
        SemanticTokensRegistrationOptions>> semanticTokensProvider;

        Json::Field<std::variant<bool, MonikerOptions,
        MonikerRegistrationOptions>> monikerProvider;

        Json::Field<std::variant<bool, TypeHierarchyOptions,
        TypeHierarchyRegistrationOptions>> typeHierarchyProvider;

        Json::Field<std::variant<bool, InlineValueOptions,
        InlineValueRegistrationOptions>> inlineValueProvider;

        Json::Field<std::variant<bool, InlayHintOptions,
        InlayHintRegistrationOptions>> inlayHintProvider;

        Json::Field<std::variant<DiagnosticOptions,
        DiagnosticRegistrationOptions>> diagnosticProvider;

        Json::Field<std::variant<bool, WorkspaceSymbolOptions>>
        workspaceSymbolProvider;

        Json::Field<Workspace2> workspace;
    };

    void from_json(const nlohmann::json&, ServerCapabilities&);

    void to_json(nlohmann::json&, const ServerCapabilities&);
}