#include "FoldingRangeRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FoldingRangeRegistrationOptions&
    frro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            frro.documentSelector = documentSelector.get<DocumentSelector>();
        frro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        frro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const FoldingRangeRegistrationOptions&
    frro)
    {
        if(frro.documentSelector.has_value())
            data["documentSelector"] = frro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(frro.workDoneProgress.Present())
            data["workDoneProgress"] = frro.workDoneProgress.Value();
        if(frro.id.Present())
            data["id"] = frro.id.Value();
    }
}