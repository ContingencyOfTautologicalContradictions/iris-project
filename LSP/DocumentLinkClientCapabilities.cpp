#include "DocumentLinkClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentLinkClientCapabilities&
    dlcc)
    {
        dlcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        dlcc.tooltipSupport = Json::Field<bool>(data, "tooltipSupport");
    }

    void to_json(nlohmann::json& data, const DocumentLinkClientCapabilities&
    dlcc)
    {
        if(dlcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dlcc.dynamicRegistration.Value();
        if(dlcc.tooltipSupport.Present())
            data["tooltipSupport"] = dlcc.tooltipSupport.Value();
    }
}