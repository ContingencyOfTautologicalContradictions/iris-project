#include "InlineValueClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, InlineValueClientCapabilities&
    ivcc)
    {
        ivcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const InlineValueClientCapabilities&
    ivcc)
    {
        if(ivcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = ivcc.dynamicRegistration.Value();
    }
}