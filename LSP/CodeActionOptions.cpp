#include "CodeActionOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CodeActionOptions& cao)
    {
        cao.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        cao.codeActionKinds = Json::Field<std::vector<std::string>>(data,
        "codeActionKinds");
        cao.resolveProvider = Json::Field<bool>(data, "resolveProvider");
    }

    void to_json(nlohmann::json& data, const CodeActionOptions& cao)
    {
        if(cao.workDoneProgress.Present())
            data["workDoneProgress"] = cao.workDoneProgress.Value();
        if(cao.codeActionKinds.Present())
            data["codeActionKinds"] = cao.codeActionKinds.Value();
        if(cao.resolveProvider.Present())
            data["resolveProvider"] = cao.resolveProvider.Value();
    }
}