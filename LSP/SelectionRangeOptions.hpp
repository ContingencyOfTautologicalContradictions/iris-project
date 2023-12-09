#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SelectionRangeOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, SelectionRangeOptions&);

    void to_json(nlohmann::json&, const SelectionRangeOptions&);
}