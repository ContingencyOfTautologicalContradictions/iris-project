#include "ParameterInformation.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ParameterInformation& pi)
    {
        pi.labelOffsetSupport = Json::Field<bool>(data, "labelOffsetSupport");
    }

    void to_json(nlohmann::json& data, const ParameterInformation& pi)
    {
        if(pi.labelOffsetSupport.Present())
            data["labelOffsetSupport"] = pi.labelOffsetSupport.Value();
    }
}