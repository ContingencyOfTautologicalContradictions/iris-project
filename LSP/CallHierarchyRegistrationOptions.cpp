#include "CallHierarchyRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CallHierarchyRegistrationOptions
    & chro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            chro.documentSelector = documentSelector.get<DocumentSelector>();
        chro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        chro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const CallHierarchyRegistrationOptions&
    chro)
    {
        if(chro.documentSelector.has_value())
            data["documentSelector"] = chro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(chro.workDoneProgress.Present())
            data["workDoneProgress"] = chro.workDoneProgress.Value();
        if(chro.id.Present())
            data["id"] = chro.id.Value();
    }
}