#include "MonikerOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, MonikerOptions& mo)
    {
        mo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const MonikerOptions& mo)
    {
        if(mo.workDoneProgress.Present())
            data["workDoneProgress"] = mo.workDoneProgress.Value();
    }
}