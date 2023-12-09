#include "LinkedEditingRangeOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, LinkedEditingRangeOptions& lero)
    {
        lero.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const LinkedEditingRangeOptions& lero)
    {
        if(lero.workDoneProgress.Present())
            data["workDoneProgress"] = lero.workDoneProgress.Value();
    }
}