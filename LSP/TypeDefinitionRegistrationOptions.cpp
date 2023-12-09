#include "TypeDefinitionRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    TypeDefinitionRegistrationOptions& tdro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            tdro.documentSelector = documentSelector.get<DocumentSelector>();
        tdro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        tdro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const TypeDefinitionRegistrationOptions&
    tdro)
    {
        if(tdro.documentSelector.has_value())
            data["documentSelector"] = tdro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(tdro.workDoneProgress.Present())
            data["workDoneProgress"] = tdro.workDoneProgress.Value();
        if(tdro.id.Present())
            data["id"] = tdro.id.Value();
    }
}