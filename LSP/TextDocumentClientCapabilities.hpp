#pragma once
#include "HoverClientCapabilities.hpp"
#include "RenameClientCapabilities.hpp"
#include "MonikerClientCapabilities.hpp"
#include "CodeLensClientCapabilities.hpp"
#include "ReferenceClientCapabilities.hpp"
#include "InlayHintClientCapabilities.hpp"
#include "CompletionClientCapabilities.hpp"
#include "DefinitionClientCapabilities.hpp"
#include "CodeActionClientCapabilities.hpp"
#include "DiagnosticClientCapabilities.hpp"
#include "DeclarationClientCapabilities.hpp"
#include "InlineValueClientCapabilities.hpp"
#include "DocumentLinkClientCapabilities.hpp"
#include "FoldingRangeClientCapabilities.hpp"
#include "SignatureHelpClientCapabilities.hpp"
#include "DocumentColorClientCapabilities.hpp"
#include "CallHierarchyClientCapabilities.hpp"
#include "TypeHierarchyClientCapabilities.hpp"
#include "TypeDefinitionClientCapabilities.hpp"
#include "ImplementationClientCapabilities.hpp"
#include "DocumentSymbolClientCapabilities.hpp"
#include "SelectionRangeClientCapabilities.hpp"
#include "SemanticTokensClientCapabilities.hpp"
#include "TextDocumentSyncClientCapabilities.hpp"
#include "DocumentHighlightClientCapabilities.hpp"
#include "DocumentFormattingClientCapabilities.hpp"
#include "PublishDiagnosticsClientCapabilities.hpp"
#include "LinkedEditingRangeClientCapabilities.hpp"
#include "DocumentRangeFormattingClientCapabilities.hpp"
#include "DocumentOnTypeFormattingClientCapabilities.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextDocumentClientCapabilities final
    {
    public:
        Json::Field<TextDocumentSyncClientCapabilities> synchronization;

        Json::Field<CompletionClientCapabilities> completion;

        Json::Field<HoverClientCapabilities> hover;

        Json::Field<SignatureHelpClientCapabilities> signatureHelp;

        Json::Field<DeclarationClientCapabilities> declaration;

        Json::Field<DefinitionClientCapabilities> definition;

        Json::Field<TypeDefinitionClientCapabilities> typeDefinition;

        Json::Field<ImplementationClientCapabilities> implementation;

        Json::Field<ReferenceClientCapabilities> reference;

        Json::Field<DocumentHighlightClientCapabilities> documentHighlight;

        Json::Field<DocumentSymbolClientCapabilities> documentSymbol;

        Json::Field<CodeActionClientCapabilities> codeAction;

        Json::Field<CodeLensClientCapabilities> codeLens;

        Json::Field<DocumentLinkClientCapabilities> documentLink;

        Json::Field<DocumentColorClientCapabilities> colorProvider;

        Json::Field<DocumentFormattingClientCapabilities> formatting;

        Json::Field<DocumentRangeFormattingClientCapabilities> rangeFormatting;

        Json::Field<DocumentOnTypeFormattingClientCapabilities>
        onTypeFormatting;

        Json::Field<RenameClientCapabilities> rename;

        Json::Field<PublishDiagnosticsClientCapabilities> publishDiagnostics;

        Json::Field<FoldingRangeClientCapabilities> foldingRange;

        Json::Field<SelectionRangeClientCapabilities> selectionRange;

        Json::Field<LinkedEditingRangeClientCapabilities> linkedEditingRange;

        Json::Field<CallHierarchyClientCapabilities> callHierarchy;

        Json::Field<SemanticTokensClientCapabilities> semanticTokens;

        Json::Field<MonikerClientCapabilities> moniker;

        Json::Field<TypeHierarchyClientCapabilities> typeHierarchy;

        Json::Field<InlineValueClientCapabilities> inlineValue;

        Json::Field<InlayHintClientCapabilities> inlayHint;

        Json::Field<DiagnosticClientCapabilities> diagnostic;
    };

    void from_json(const nlohmann::json&, TextDocumentClientCapabilities&);

    void to_json(nlohmann::json&, const TextDocumentClientCapabilities&);
}