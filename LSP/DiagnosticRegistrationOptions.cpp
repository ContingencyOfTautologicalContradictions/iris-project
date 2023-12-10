#include "DiagnosticRegistratonOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DiagnosticRegistrationOptions&
    dro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            dro.documentSelector = documentSelector.get<DocumentSelector>();
        dro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        dro.identifier = Json::Field<std::string>(data, "identifier");
        dro.interFileDependencies = data.at("interFileDependencies").get<bool>(
        );
        dro.workspaceDiagnostics = data.at("workspaceDiagnostics").get<bool>();
        dro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const DiagnosticRegistrationOptions& dro)
    {
        if(dro.documentSelector.has_value())
            data["documentSelector"] = dro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(dro.workDoneProgress.Present())
            data["workDoneProgress"] = dro.workDoneProgress.Value();
        if(dro.identifier.Present())
            data["identifier"] = dro.identifier.Value();
        data["interFileDependencies"] = dro.interFileDependencies;
        data["workspaceDiagnostics"] = dro.workspaceDiagnostics;
        if(dro.id.Present())
            data["id"] = dro.id.Value();
    }
}