#include "InlineValueRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, InlineValueRegistrationOptions&
    ivro)
    {
        ivro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            ivro.documentSelector = documentSelector.get<DocumentSelector>();
        ivro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const InlineValueRegistrationOptions& ivro)
    {
        if(ivro.workDoneProgress.Present())
            data["workDoneProgress"] = ivro.workDoneProgress.Value();
        if(ivro.documentSelector.has_value())
            data["documentSelector"] = ivro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(ivro.id.Present())
            data["id"] = ivro.id.Value();
    }
}