#include "DocumentOnTypeFormattingClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    DocumentOnTypeFormattingClientCapabilities& dotfcc)
    {
        dotfcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const
    DocumentOnTypeFormattingClientCapabilities& dotfcc)
    {
        if(dotfcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dotfcc.dynamicRegistration.Value();
    }
}