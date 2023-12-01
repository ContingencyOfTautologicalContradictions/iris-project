#include "DefinitionClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DefinitionClientCapabilities&
    dcc)
    {
        dcc.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration"
        );
        dcc.linkSupport = Json::Field<bool>(data, "linkSupport");
    }

    void to_json(nlohmann::json& data, const DefinitionClientCapabilities& dcc)
    {
        if(dcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dcc.dynamicRegistration.Value();
        if(dcc.linkSupport.Present())
            data["linkSupport"] = dcc.linkSupport.Value();
    }
}