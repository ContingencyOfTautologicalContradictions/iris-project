#pragma once
#include "ESymbolKind.hpp"
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SymbolKind final
    {
    public:
        Json::Field<std::vector<ESymbolKind>> valueSet;
    };

    void from_json(const nlohmann::json&, SymbolKind&);

    void to_json(nlohmann::json&, const SymbolKind&);
}