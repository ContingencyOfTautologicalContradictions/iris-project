#include "HoverClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, HoverClientCapabilities& hcc)
    {
        hcc.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration"
        );
        hcc.contentFormat = Json::Field<std::vector<MarkupKind>>(data,
        "contentFormat");
    }

    void to_json(nlohmann::json& data, const HoverClientCapabilities& hcc)
    {
        if(hcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = hcc.dynamicRegistration.Value();
        if(hcc.contentFormat.Present())
            data["contentFormat"] = hcc.contentFormat.Value();
    }
}