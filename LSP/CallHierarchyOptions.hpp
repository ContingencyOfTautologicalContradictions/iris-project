#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CallHierarchyOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, CallHierarchyOptions&);

    void to_json(nlohmann::json&, const CallHierarchyOptions&);
}