#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] LinkedEditingRangeOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, LinkedEditingRangeOptions&);

    void to_json(nlohmann::json&, const LinkedEditingRangeOptions&);
}