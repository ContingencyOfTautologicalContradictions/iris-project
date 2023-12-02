#include "MonikerClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, MonikerClientCapabilities& mcc)
    {
        mcc.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration"
        );
    }

    void to_json(nlohmann::json& data, const MonikerClientCapabilities& mcc)
    {
        if(mcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = mcc.dynamicRegistration.Value();
    }
}