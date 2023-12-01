#include "DocumentHighlightClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    DocumentHighlightClientCapabilities& dhcc)
    {
        dhcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const
    DocumentHighlightClientCapabilities& dhcc)
    {
        if(dhcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dhcc.dynamicRegistration.Value();
    }
}