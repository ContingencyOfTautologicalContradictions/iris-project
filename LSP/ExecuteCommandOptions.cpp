#include "ExecuteCommandOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ExecuteCommandOptions& eco)
    {
        eco.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        eco.commands = data.at("commands").get<std::vector<std::string>>();
    }

    void to_json(nlohmann::json& data, const ExecuteCommandOptions& eco)
    {
        if(eco.workDoneProgress.Present())
            data["workDoneProgress"] = eco.workDoneProgress.Value();
        data["commands"] = eco.commands;
    }
}