#include "InlayHintRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, InlayHintRegistrationOptions&
    ihro)
    {
        ihro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        ihro.resolveProvider = Json::Field<bool>(data, "resolveProvider");
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            ihro.documentSelector = documentSelector.get<DocumentSelector>();
        ihro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const InlayHintRegistrationOptions& ihro
    )
    {
        if(ihro.workDoneProgress.Present())
            data["workDoneProgress"] = ihro.workDoneProgress.Value();
        if(ihro.resolveProvider.Present())
            data["resolveProvider"] = ihro.resolveProvider.Value();
        if(ihro.documentSelector.has_value())
            data["documentSelector"] = ihro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(ihro.id.Present())
            data["id"] = ihro.id.Value();
    }
}