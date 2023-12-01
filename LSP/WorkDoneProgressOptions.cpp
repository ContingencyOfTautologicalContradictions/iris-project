#include "WorkDoneProgressOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, WorkDoneProgressOptions& wdpo)
    {
        wdpo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const WorkDoneProgressOptions& wdpo)
    {
        if(wdpo.workDoneProgress.Present())
            data["workDoneProgress"] = wdpo.workDoneProgress.Value();
    }
}