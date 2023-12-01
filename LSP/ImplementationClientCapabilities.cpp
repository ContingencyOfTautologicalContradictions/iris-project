#include "ImplementationClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ImplementationClientCapabilities
    & icc)
    {
        icc.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration"
        );
        icc.linkSupport = Json::Field<bool>(data, "linkSupport");
    }

    void to_json(nlohmann::json& data, const ImplementationClientCapabilities&
    icc)
    {
        if(icc.dynamicRegistration.Present())
            data["dynamicRegistration"] = icc.dynamicRegistration.Value();
        if(icc.linkSupport.Present())
            data["linkSupport"] = icc.linkSupport.Value();
    }
}