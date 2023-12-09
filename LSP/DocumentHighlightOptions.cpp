#include "DocumentHighlightOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentHighlightOptions& dho)
    {
        dho.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const DocumentHighlightOptions& dho)
    {
        if(dho.workDoneProgress.Present())
            data["workDoneProgress"] = dho.workDoneProgress.Value();
    }
}