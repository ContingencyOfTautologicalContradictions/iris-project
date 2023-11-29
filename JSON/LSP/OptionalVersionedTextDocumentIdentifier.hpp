#pragma once
#include "URI.hpp"
#include "../Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] OptionalVersionedTextDocumentIdentifier final
    {
    public:
        DocumentUri uri;

        std::optional<std::int64_t> version;
    };

    void from_json(const nlohmann::json&,
    OptionalVersionedTextDocumentIdentifier&);

    void to_json(nlohmann::json&, const OptionalVersionedTextDocumentIdentifier
    &);
}