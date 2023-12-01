#include "DocumentColorClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentColorClientCapabilities&
    dccc)
    {
        dccc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const DocumentColorClientCapabilities&
    dccc)
    {
        if(dccc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dccc.dynamicRegistration.Value();
    }
}