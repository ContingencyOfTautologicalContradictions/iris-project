#include "WorkspaceSymbolOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, WorkspaceSymbolOptions& wso)
    {
        wso.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        wso.resolveProvider = Json::Field<bool>(data, "resolveProvider");
    }

    void to_json(nlohmann::json& data, const WorkspaceSymbolOptions& wso)
    {
        if(wso.workDoneProgress.Present())
            data["workDoneProgress"] = wso.workDoneProgress.Value();
        if(wso.resolveProvider.Present())
            data["resolveProvider"] = wso.resolveProvider.Value();
    }
}