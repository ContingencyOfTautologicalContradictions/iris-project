#pragma once
#include "../Json.hpp"

namespace Iris::LSP
{
    using MarkupKind = std::string;

    class [[nodiscard]] MarkupContent final
    {
    public:
        MarkupKind kind;

        std::string value;
    };

    void from_json(const nlohmann::json&, MarkupContent&);

    void to_json(nlohmann::json&, const MarkupContent&);
}