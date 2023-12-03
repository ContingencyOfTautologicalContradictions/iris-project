#include "TextDocumentClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TextDocumentClientCapabilities&
    tdcc)
    {
        tdcc.synchronization = Json::Field<TextDocumentSyncClientCapabilities>(
        data, "synchronization");
        tdcc.completion = Json::Field<CompletionClientCapabilities>(data,
        "completion");
        tdcc.hover = Json::Field<HoverClientCapabilities>(data, "hover");
        tdcc.signatureHelp = Json::Field<SignatureHelpClientCapabilities>(data,
        "signatureHelp");
        tdcc.declaration = Json::Field<DeclarationClientCapabilities>(data,
        "declaration");
        tdcc.definition = Json::Field<DefinitionClientCapabilities>(data,
        "definition");
        tdcc.typeDefinition = Json::Field<TypeDefinitionClientCapabilities>(
        data, "typeDefinition");
        tdcc.implementation = Json::Field<ImplementationClientCapabilities>(
        data, "implementation");
        tdcc.reference = Json::Field<ReferenceClientCapabilities>(data,
        "reference");
        tdcc.documentHighlight = Json::Field<
        DocumentHighlightClientCapabilities>(data, "documentHighlight");
        tdcc.documentSymbol = Json::Field<DocumentSymbolClientCapabilities>(
        data, "documentSymbol");
        tdcc.codeAction = Json::Field<CodeActionClientCapabilities>(data,
        "codeAction");
        tdcc.codeLens = Json::Field<CodeLensClientCapabilities>(data,
        "codeLens");
        tdcc.documentLink = Json::Field<DocumentLinkClientCapabilities>(data,
        "documentLink");
        tdcc.colorProvider = Json::Field<DocumentColorClientCapabilities>(data,
        "colorProvider");
        tdcc.formatting = Json::Field<DocumentFormattingClientCapabilities>(
        data, "formatting");
        tdcc.rangeFormatting = Json::Field<
        DocumentRangeFormattingClientCapabilities>(data, "rangeFormatting");
        tdcc.onTypeFormatting = Json::Field<
        DocumentOnTypeFormattingClientCapabilities>(data, "onTypeFormatting");
        tdcc.rename = Json::Field<RenameClientCapabilities>(data, "rename");
        tdcc.publishDiagnostics = Json::Field<
        PublishDiagnosticsClientCapabilities>(data, "publishDiagnostics");
        tdcc.foldingRange = Json::Field<FoldingRangeClientCapabilities>(data,
        "foldingRange");
        tdcc.selectionRange = Json::Field<SelectionRangeClientCapabilities>(
        data, "selectionRange");
        tdcc.linkedEditingRange = Json::Field<
        LinkedEditingRangeClientCapabilities>(data, "linkedEditingRange");
        tdcc.callHierarchy = Json::Field<CallHierarchyClientCapabilities>(data,
        "callHierarchy");
        tdcc.semanticTokens = Json::Field<SemanticTokensClientCapabilities>(
        data, "semanticTokens");
        tdcc.moniker = Json::Field<MonikerClientCapabilities>(data, "moniker");
        tdcc.typeHierarchy = Json::Field<TypeHierarchyClientCapabilities>(data,
        "typeHierarchy");
        tdcc.inlineValue = Json::Field<InlineValueClientCapabilities>(data,
        "inlineValue");
        tdcc.inlayHint = Json::Field<InlayHintClientCapabilities>(data,
        "inlayHint");
        tdcc.diagnostic = Json::Field<DiagnosticClientCapabilities>(data,
        "diagnostic");
    }

    void to_json(nlohmann::json& data, const TextDocumentClientCapabilities&
    tdcc)
    {
        if(tdcc.synchronization.Present())
            data["synchronization"] = tdcc.synchronization.Value();
        if(tdcc.completion.Present())
            data["completion"] = tdcc.completion.Value();
        if(tdcc.hover.Present())
            data["hover"] = tdcc.hover.Value();
        if(tdcc.signatureHelp.Present())
            data["signatureHelp"] = tdcc.signatureHelp.Value();
        if(tdcc.declaration.Present())
            data["declaration"] = tdcc.declaration.Value();
        if(tdcc.definition.Present())
            data["definition"] = tdcc.definition.Value();
        if(tdcc.typeDefinition.Present())
            data["typeDefinition"] = tdcc.typeDefinition.Value();
        if(tdcc.implementation.Present())
            data["implementation"] = tdcc.implementation.Value();
        if(tdcc.reference.Present())
            data["reference"] = tdcc.reference.Value();
        if(tdcc.documentHighlight.Present())
            data["documentHighlight"] = tdcc.documentHighlight.Value();
        if(tdcc.documentSymbol.Present())
            data["documentSymbol"] = tdcc.documentSymbol.Value();
        if(tdcc.codeAction.Present())
            data["codeAction"] = tdcc.codeAction.Value();
        if(tdcc.codeLens.Present())
            data["codeLens"] = tdcc.codeLens.Value();
        if(tdcc.documentLink.Present())
            data["documentLink"] = tdcc.documentLink.Value();
        if(tdcc.colorProvider.Present())
            data["colorProvider"] = tdcc.colorProvider.Value();
        if(tdcc.formatting.Present())
            data["formatting"] = tdcc.formatting.Value();
        if(tdcc.rangeFormatting.Present())
            data["rangeFormatting"] = tdcc.rangeFormatting.Value();
        if(tdcc.onTypeFormatting.Present())
            data["onTypeFormatting"] = tdcc.onTypeFormatting.Value();
        if(tdcc.rename.Present())
            data["rename"] = tdcc.rename.Value();
        if(tdcc.publishDiagnostics.Present())
            data["publishDiagnostics"] = tdcc.publishDiagnostics.Value();
        if(tdcc.foldingRange.Present())
            data["foldingRange"] = tdcc.foldingRange.Value();
        if(tdcc.selectionRange.Present())
            data["selectionRange"] = tdcc.selectionRange.Value();
        if(tdcc.linkedEditingRange.Present())
            data["linkedEditingRange"] = tdcc.linkedEditingRange.Value();
        if(tdcc.callHierarchy.Present())
            data["callHierarchy"] = tdcc.callHierarchy.Value();
        if(tdcc.semanticTokens.Present())
            data["semanticTokens"] = tdcc.semanticTokens.Value();
        if(tdcc.moniker.Present())
            data["moniker"] = tdcc.moniker.Value();
        if(tdcc.typeHierarchy.Present())
            data["typeHierarchy"] = tdcc.typeHierarchy.Value();
        if(tdcc.inlineValue.Present())
            data["inlineValue"] = tdcc.inlineValue.Value();
        if(tdcc.inlayHint.Present())
            data["inlayHint"] = tdcc.inlayHint.Value();
        if(tdcc.diagnostic.Present())
            data["diagnostic"] = tdcc.diagnostic.Value();
    }
}