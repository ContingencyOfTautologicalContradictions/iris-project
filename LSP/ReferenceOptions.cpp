#include "ReferenceOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ReferenceOptions& ro)
    {
        ro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const ReferenceOptions& ro)
    {
        if(ro.workDoneProgress.Present())
            data["workDoneProgress"] = ro.workDoneProgress.Value();
    }
}