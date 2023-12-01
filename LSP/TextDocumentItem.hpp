#pragma once
#include "URI.hpp"
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextDocumentItem final
    {
    public:
        DocumentUri uri;

        std::string languageId;

        std::int64_t version;

        std::string text;
    };

    void from_json(const nlohmann::json&, TextDocumentItem&);

    void to_json(nlohmann::json&, const TextDocumentItem&);
}