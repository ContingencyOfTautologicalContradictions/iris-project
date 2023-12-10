#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InlineValueOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, InlineValueOptions&);

    void to_json(nlohmann::json&, const InlineValueOptions&);
}