#include "CallHierarchyOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CallHierarchyOptions& cho)
    {
        cho.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const CallHierarchyOptions& cho)
    {
        if(cho.workDoneProgress.Present())
            data["workDoneProgress"] = cho.workDoneProgress.Value();
    }
}