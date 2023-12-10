#include "InlayHintOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, InlayHintOptions& iho)
    {
        iho.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        iho.resolveProvider = Json::Field<bool>(data, "resolveProvider");
    }

    void to_json(nlohmann::json& data, const InlayHintOptions& iho)
    {
        if(iho.workDoneProgress.Present())
            data["workDoneProgress"] = iho.workDoneProgress.Value();
        if(iho.resolveProvider.Present())
            data["resolveProvider"] = iho.resolveProvider.Value();
    }
}