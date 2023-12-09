#include "SignatureHelpOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SignatureHelpOptions& sho)
    {
        sho.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        sho.triggerCharacters = Json::Field<std::vector<std::string>>(data,
        "triggerCharacters");
        sho.retriggerCharacters = Json::Field<std::vector<std::string>>(data,
        "retriggerCharacters");
    }

    void to_json(nlohmann::json& data, const SignatureHelpOptions& sho)
    {
        if(sho.workDoneProgress.Present())
            data["workDoneProgress"] = sho.workDoneProgress.Value();
        if(sho.triggerCharacters.Present())
            data["triggerCharacters"] = sho.triggerCharacters.Value();
        if(sho.retriggerCharacters.Present())
            data["retriggerCharacters"] = sho.retriggerCharacters.Value();
    }
}