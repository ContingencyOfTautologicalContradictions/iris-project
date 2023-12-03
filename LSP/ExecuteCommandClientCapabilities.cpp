#include "ExecuteCommandClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ExecuteCommandClientCapabilities
    & eccc)
    {
        eccc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const ExecuteCommandClientCapabilities&
    eccc)
    {
        if(eccc.dynamicRegistration.Present())
            data["dynamicRegistration"] = eccc.dynamicRegistration.Value();
    }
}