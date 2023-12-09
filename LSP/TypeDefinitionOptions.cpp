#include "TypeDefinitionOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TypeDefinitionOptions& tdo)
    {
        tdo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const TypeDefinitionOptions& tdo)
    {
        if(tdo.workDoneProgress.Present())
            data["workDoneProgress"] = tdo.workDoneProgress.Value();
    }
}