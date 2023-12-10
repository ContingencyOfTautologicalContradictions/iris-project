#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TypeHierarchyOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, TypeHierarchyOptions&);

    void to_json(nlohmann::json&, const TypeHierarchyOptions&);
}