#include "ImplementationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ImplementationOptions& io)
    {
        io.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const ImplementationOptions& io)
    {
        if(io.workDoneProgress.Present())
            data["workDoneProgress"] = io.workDoneProgress.Value();
    }
}