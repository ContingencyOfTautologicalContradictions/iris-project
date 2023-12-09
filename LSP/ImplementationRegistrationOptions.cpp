#include "ImplementationRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    ImplementationRegistrationOptions& iro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(documentSelector.is_object())
            iro.documentSelector = documentSelector.get<DocumentSelector>();
        iro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        iro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const ImplementationRegistrationOptions&
    iro)
    {
        if(iro.documentSelector.has_value())
            data["documentSelector"] = iro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(iro.workDoneProgress.Present())
            data["workDoneProgress"] = iro.workDoneProgress.Value();
        if(iro.id.Present())
            data["id"] = iro.id.Value();
    }
}