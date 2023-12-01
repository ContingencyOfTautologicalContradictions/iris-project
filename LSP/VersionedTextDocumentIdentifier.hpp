#pragma once
#include "URI.hpp"
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] VersionedTextDocumentIdentifier final
    {
    public:
        DocumentUri uri;

        std::int64_t version;
    };

    void from_json(const nlohmann::json&, VersionedTextDocumentIdentifier&);

    void to_json(nlohmann::json&, const VersionedTextDocumentIdentifier&);
}