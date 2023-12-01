#pragma once
#include "MarkupKind.hpp"
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] MarkupContent final
    {
    public:
        MarkupKind kind;

        std::string value;
    };

    void from_json(const nlohmann::json&, MarkupContent&);

    void to_json(nlohmann::json&, const MarkupContent&);
}