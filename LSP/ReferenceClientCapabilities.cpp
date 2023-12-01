#include "ReferenceClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ReferenceClientCapabilities& rcc
    )
    {
        rcc.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration"
        );
    }

    void to_json(nlohmann::json& data, const ReferenceClientCapabilities&
    rcc)
    {
        if(rcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = rcc.dynamicRegistration.Value();
    }
}