#include "SemanticTokensWorkspaceClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    SemanticTokensWorkspaceClientCapabilities& stwcc)
    {
        stwcc.refreshSupport = Json::Field<bool>(data, "refreshSupport");
    }

    void to_json(nlohmann::json& data, const
    SemanticTokensWorkspaceClientCapabilities& stwcc)
    {
        if(stwcc.refreshSupport.Present())
            data["refreshSupport"] = stwcc.refreshSupport.Value();
    }
}