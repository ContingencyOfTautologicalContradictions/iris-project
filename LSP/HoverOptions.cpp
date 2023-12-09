#include "HoverOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, HoverOptions& ho)
    {
        ho.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const HoverOptions& ho)
    {
        if(ho.workDoneProgress.Present())
            data["workDoneProgress"] = ho.workDoneProgress.Value();
    }
}