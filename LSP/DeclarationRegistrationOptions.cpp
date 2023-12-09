#include "DeclarationRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DeclarationRegistrationOptions&
    dro)
    {
        dro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(documentSelector.is_object())
            dro.documentSelector = documentSelector.get<DocumentSelector>();
        dro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const DeclarationRegistrationOptions&
    dro)
    {
        if(dro.workDoneProgress.Present())
            data["workDoneProgress"] = dro.workDoneProgress.Value();
        if(dro.documentSelector.has_value())
            data["documentSelector"] = dro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(dro.id.Present())
            data["id"] = dro.id.Value();
    }
}