#include "CodeLensOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CodeLensOptions& clo)
    {
        clo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        clo.resolveProvider = Json::Field<bool>(data, "resolveProvider");
    }

    void to_json(nlohmann::json& data, const CodeLensOptions& clo)
    {
        if(clo.workDoneProgress.Present())
            data["workDoneProgress"] = clo.workDoneProgress.Value();
        if(clo.resolveProvider.Present())
            data["resolveProvider"] = clo.resolveProvider.Value();
    }
}