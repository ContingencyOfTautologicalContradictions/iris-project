#include "CallHierarchyClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CallHierarchyClientCapabilities&
    chcc)
    {
        chcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const CallHierarchyClientCapabilities&
    chcc)
    {
        if(chcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = chcc.dynamicRegistration.Value();
    }
}