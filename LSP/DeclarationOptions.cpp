#include "DeclarationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DeclarationOptions& vdo)
    {
        vdo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const DeclarationOptions& vdo)
    {
        if(vdo.workDoneProgress.Present())
            data["workDoneProgress"] = vdo.workDoneProgress.Value();
    }
}