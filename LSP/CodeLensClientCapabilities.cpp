#include "CodeLensClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CodeLensClientCapabilities& clcc
    )
    {
        clcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const CodeLensClientCapabilities& clcc)
    {
        if(clcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = clcc.dynamicRegistration.Value();
    }
}