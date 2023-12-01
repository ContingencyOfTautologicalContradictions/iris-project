#pragma once
#include "Position.hpp"
#include "TextDocumentIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextDocumentPositionParams final
    {
    public:
        TextDocumentIdentifier textDocument;

        Position position;
    };

    void from_json(const nlohmann::json&, TextDocumentPositionParams&);

    void to_json(nlohmann::json&, const TextDocumentPositionParams&);
}