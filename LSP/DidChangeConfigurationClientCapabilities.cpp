#include "DidChangeConfigurationClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    DidChangeConfigurationClientCapabilities& dcccc)
    {
        dcccc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const
    DidChangeConfigurationClientCapabilities& dcccc)
    {
        if(dcccc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dcccc.dynamicRegistration.Value();
    }
}