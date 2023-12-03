#include "InlayHintWorkspaceClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    InlayHintWorkspaceClientCapabilities& ihwcc)
    {
        ihwcc.refreshSupport = Json::Field<bool>(data, "refreshSupport");
    }

    void to_json(nlohmann::json& data, const
    InlayHintWorkspaceClientCapabilities& ihwcc)
    {
        if(ihwcc.refreshSupport.Present())
            data["refreshSupport"] = ihwcc.refreshSupport.Value();
    }
}