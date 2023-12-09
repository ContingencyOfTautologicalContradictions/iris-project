#include "SelectionRangeOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SelectionRangeOptions& sro)
    {
        sro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const SelectionRangeOptions& sro)
    {
        if(sro.workDoneProgress.Present())
            data["workDoneProgress"] = sro.workDoneProgress.Value();
    }
}