#pragma once
#include "TextEdit.hpp"
#include "AnnotatedTextEdit.hpp"
#include "OptionalVersionedTextDocumentIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextDocumentEdit final
    {
    public:
        OptionalVersionedTextDocumentIdentifier textDocument;

        std::vector<std::variant<TextEdit, AnnotatedTextEdit>> edits;
    };

    void from_json(const nlohmann::json&, TextDocumentEdit&);

    void to_json(nlohmann::json&, const TextDocumentEdit&);
}