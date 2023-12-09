#include "DocumentColorRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentColorRegistrationOptions
    & dcro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            dcro.documentSelector = documentSelector.get<DocumentSelector>();
        dcro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        dcro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const DocumentColorRegistrationOptions&
    dcro)
    {
        if(dcro.documentSelector.has_value())
            data["documentSelector"] = dcro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(dcro.workDoneProgress.Present())
            data["workDoneProgress"] = dcro.workDoneProgress.Value();
        if(dcro.id.Present())
            data["id"] = dcro.id.Value();
    }
}