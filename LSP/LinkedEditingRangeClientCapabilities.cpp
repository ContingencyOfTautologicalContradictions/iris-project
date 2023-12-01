#include "LinkedEditingRangeClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    LinkedEditingRangeClientCapabilities& lercc)
    {
        lercc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const
    LinkedEditingRangeClientCapabilities& lercc)
    {
        if(lercc.dynamicRegistration.Present())
            data["dynamicRegistration"] = lercc.dynamicRegistration.Value();
    }
}