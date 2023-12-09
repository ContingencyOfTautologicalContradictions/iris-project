#include "FoldingRangeOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FoldingRangeOptions& fro)
    {
        fro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }
    
    void to_json(nlohmann::json& data, const FoldingRangeOptions& fro)
    {
        if(fro.workDoneProgress.Present())
            data["workDoneProgress"] = fro.workDoneProgress.Value();
    }
}