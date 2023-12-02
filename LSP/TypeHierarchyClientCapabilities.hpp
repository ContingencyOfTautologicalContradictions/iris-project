#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TypeHierarchyClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, TypeHierarchyClientCapabilities&);

    void to_json(nlohmann::json&, const TypeHierarchyClientCapabilities&);
}