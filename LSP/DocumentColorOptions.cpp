#include "DocumentColorOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentColorOptions& dco)
    {
        dco.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const DocumentColorOptions& dco)
    {
        if(dco.workDoneProgress.Present())
            data["workDoneProgress"] = dco.workDoneProgress.Value();
    }
}