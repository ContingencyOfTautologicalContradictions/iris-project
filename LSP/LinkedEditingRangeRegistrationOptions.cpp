#include "LinkedEditingRangeRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    LinkedEditingRangeRepresentationOptions& lerro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            lerro.documentSelector = documentSelector.get<DocumentSelector>();
        lerro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        lerro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const
    LinkedEditingRangeRepresentationOptions& lerro)
    {
        if(lerro.documentSelector.has_value())
            data["documentSelector"] = lerro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(lerro.workDoneProgress.Present())
            data["workDoneProgress"] = lerro.workDoneProgress.Value();
        if(lerro.id.Present())
            data["id"] = lerro.id.Value();
    }
}