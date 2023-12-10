#include "DiagnosticOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DiagnosticOptions& vdo)
    {
        vdo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        vdo.identifier = Json::Field<std::string>(data, "identifier");
        vdo.interFileDependencies = data.at("interFileDependencies").get<bool>(
        );
        vdo.workspaceDiagnostics = data.at("workspaceDiagnostics").get<bool>();
    }

    void to_json(nlohmann::json& data, const DiagnosticOptions& vdo)
    {
        if(vdo.workDoneProgress.Present())
            data["workDoneProgress"] = vdo.workDoneProgress.Value();
        if(vdo.identifier.Present())
            data["identifier"] = vdo.identifier.Value();
        data["interFileDependencies"] = vdo.interFileDependencies;
        data["workspaceDiagnostics"] = vdo.workspaceDiagnostics;
    }
}