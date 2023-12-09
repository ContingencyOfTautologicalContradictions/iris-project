#include "DefinitionOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DefinitionOptions& vdo)
    {
        vdo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const DefinitionOptions& vdo)
    {
        if(vdo.workDoneProgress.Present())
            data["workDoneProgress"] = vdo.workDoneProgress.Value();
    }
}