#include "DocumentRangeFormattingOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentRangeFormattingOptions&
    drfo)
    {
        drfo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const DocumentRangeFormattingOptions&
    drfo)
    {
        if(drfo.workDoneProgress.Present())
            data["workDoneProgress"] = drfo.workDoneProgress.Value();
    }
}