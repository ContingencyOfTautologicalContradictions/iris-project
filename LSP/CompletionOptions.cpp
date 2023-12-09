#include "CompletionOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CompletionOptions& co)
    {
        co.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        co.triggerCharacters = Json::Field<std::vector<std::string>>(data,
        "triggerCharacters");
        co.allCommitCharacters = Json::Field<std::vector<std::string>>(data,
        "allCommitCharacters");
        co.resolveProvider = Json::Field<bool>(data, "resolveProvider");
        co.completionItem = Json::Field<CompletionItem2>(data, "completionItem"
        );
    }

    void to_json(nlohmann::json& data, const CompletionOptions& co)
    {
        if(co.workDoneProgress.Present())
            data["workDoneProgress"] = co.workDoneProgress.Value();
        if(co.triggerCharacters.Present())
            data["triggerCharacters"] = co.triggerCharacters.Value();
        if(co.allCommitCharacters.Present())
            data["allCommitCharacters"] = co.allCommitCharacters.Value();
        if(co.resolveProvider.Present())
            data["resolveProvider"] = co.resolveProvider.Value();
        if(co.completionItem.Present())
            data["completionItem"] = co.completionItem.Value();
    }
}