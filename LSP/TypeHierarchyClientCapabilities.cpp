#include "TypeHierarchyClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TypeHierarchyClientCapabilities&
    thcc)
    {
        thcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const TypeHierarchyClientCapabilities&
    thcc)
    {
        if(thcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = thcc.dynamicRegistration.Value();
    }
}