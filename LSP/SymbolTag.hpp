#pragma once
#include "ESymbolTag.hpp"
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SymbolTag final
    {
    public:
        std::vector<ESymbolTag> valueSet;
    };

    void from_json(const nlohmann::json&, SymbolTag&);

    void to_json(nlohmann::json&, const SymbolTag&);
}