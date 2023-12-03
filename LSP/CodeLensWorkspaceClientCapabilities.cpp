#include "CodeLensWorkspaceClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    CodeLensWorkspaceClientCapabilities& clwcc)
    {
        clwcc.refreshSupport = Json::Field<bool>(data, "refreshSupport");
    }

    void to_json(nlohmann::json& data, const
    CodeLensWorkspaceClientCapabilities& clwcc)
    {
        if(clwcc.refreshSupport.Present())
            data["refreshSupport"] = clwcc.refreshSupport.Value();
    }
}