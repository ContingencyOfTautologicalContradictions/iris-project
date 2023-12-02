#include "InlayHintClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, InlayHintClientCapabilities&
    ihcc)
    {
        ihcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        ihcc.resolveSupport = Json::Field<ResolveSupport>(data,
        "resolveSupport");
    }

    void to_json(nlohmann::json& data, const InlayHintClientCapabilities& ihcc)
    {
        if(ihcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = ihcc.dynamicRegistration.Value();
        if(ihcc.resolveSupport.Present())
            data["resolveSupport"] = ihcc.resolveSupport.Value();
    }
}