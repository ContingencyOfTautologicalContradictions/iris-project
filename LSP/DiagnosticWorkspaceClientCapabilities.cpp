#include "DiagnosticWorkspaceClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    DiagnosticWorkspaceClientCapabilities& dwcc)
    {
        dwcc.refreshSupport = Json::Field<bool>(data, "refreshSupport");
    }

    void to_json(nlohmann::json& data, const
    DiagnosticWorkspaceClientCapabilities& dwcc)
    {
        if(dwcc.refreshSupport.Present())
            data["refreshSupport"] = dwcc.refreshSupport.Value();
    }
}