#include "InlineValueOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, InlineValueOptions& ivo)
    {
        ivo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const InlineValueOptions& ivo)
    {
        if(ivo.workDoneProgress.Present())
            data["workDoneProgress"] = ivo.workDoneProgress.Value();
    }
}