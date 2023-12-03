#include "InlineValueWorkspaceClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    InlineValueWorkspaceClientCapabilities& ivwcc)
    {
        ivwcc.refreshSupport = Json::Field<bool>(data, "refreshSupport");
    }

    void to_json(nlohmann::json& data, const
    InlineValueWorkspaceClientCapabilities& ivwcc)
    {
        if(ivwcc.refreshSupport.Present())
            data["refreshSupport"] = ivwcc.refreshSupport.Value();
    }
}