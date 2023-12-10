#include "TypeHierarchyRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TypeHierarchyRegistrationOptions
    & thro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            thro.documentSelector = documentSelector.get<DocumentSelector>();
        thro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        thro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const TypeHierarchyRegistrationOptions&
    thro)
    {
        if(thro.documentSelector.has_value())
            data["documentSelector"] = thro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(thro.workDoneProgress.Present())
            data["workDoneProgress"] = thro.workDoneProgress.Value();
        if(thro.id.Present())
            data["id"] = thro.id.Value();
    }
}