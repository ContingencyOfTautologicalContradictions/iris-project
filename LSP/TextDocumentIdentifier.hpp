#pragma once
#include "URI.hpp"
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextDocumentIdentifier final
    {
    public:
        DocumentUri uri;
    };

    void from_json(const nlohmann::json&, TextDocumentIdentifier&);

    void to_json(nlohmann::json&, const TextDocumentIdentifier&);
}