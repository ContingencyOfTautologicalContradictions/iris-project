#include "DocumentFormattingOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentFormattingOptions& dfo)
    {
        dfo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const DocumentFormattingOptions& dfo)
    {
        if(dfo.workDoneProgress.Present())
            data["workDoneProgress"] = dfo.workDoneProgress.Value();
    }
}