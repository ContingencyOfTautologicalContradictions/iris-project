#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FoldingRangeOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, FoldingRangeOptions&);

    void to_json(nlohmann::json&, const FoldingRangeOptions&);
}