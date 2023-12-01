#include "TypeDefinitionClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TypeDefinitionClientCapabilities
    & tdcc)
    {
        tdcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        tdcc.linkSupport = Json::Field<bool>(data, "linkSupport");
    }

    void to_json(nlohmann::json& data, const TypeDefinitionClientCapabilities&
    tdcc)
    {
        if(tdcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = tdcc.dynamicRegistration.Value();
        if(tdcc.linkSupport.Present())
            data["linkSupport"] = tdcc.linkSupport.Value();
    }
}