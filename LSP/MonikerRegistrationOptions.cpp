#include "MonikerRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, MonikerRegistrationOptions& mro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            mro.documentSelector = documentSelector.get<DocumentSelector>();
        mro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const MonikerRegistrationOptions& mro)
    {
        if(mro.documentSelector.has_value())
            data["documentSelector"] = mro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(mro.workDoneProgress.Present())
            data["workDoneProgress"] = mro.workDoneProgress.Value();
    }
}