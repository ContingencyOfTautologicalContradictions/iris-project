#include "DocumentFormattingClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    DocumentFormattingClientCapabilities& dfcc)
    {
        dfcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const
    DocumentFormattingClientCapabilities& dfcc)
    {
        if(dfcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dfcc.dynamicRegistration.Value();
    }
}