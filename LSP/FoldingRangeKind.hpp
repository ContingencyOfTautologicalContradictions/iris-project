#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FoldingRangeKind final
    {
    public:
        Json::Field<std::vector<std::string>> valueSet;
    };

    void from_json(const nlohmann::json&, FoldingRangeKind&);

    void to_json(nlohmann::json&, const FoldingRangeKind&);
}