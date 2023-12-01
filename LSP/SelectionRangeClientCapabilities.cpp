#include "SelectionRangeClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SelectionRangeClientCapabilities
    & srcc)
    {
        srcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
    }

    void to_json(nlohmann::json& data, const SelectionRangeClientCapabilities&
    srcc)
    {
        if(srcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = srcc.dynamicRegistration.Value();
    }
}