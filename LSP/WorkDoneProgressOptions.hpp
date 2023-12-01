#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkDoneProgressOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, WorkDoneProgressOptions&);

    void to_json(nlohmann::json&, const WorkDoneProgressOptions&);
}