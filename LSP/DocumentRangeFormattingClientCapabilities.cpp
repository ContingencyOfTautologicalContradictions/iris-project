#include "DocumentRangeFormattingClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    DocumentRangeFormattingClientCapabilities& drfcc)
    {
        drfcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const
    DocumentRangeFormattingClientCapabilities& drfcc)
    {
        if(drfcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = drfcc.dynamicRegistration.Value();
    }
}