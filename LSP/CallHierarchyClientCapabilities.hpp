#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CallHierarchyClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, CallHierarchyClientCapabilities&);

    void to_json(nlohmann::json&, const CallHierarchyClientCapabilities&);
}