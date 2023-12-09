#include "SelectionRangeRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    SelectionRangeRegistrationOptions& srro)
    {
        srro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            srro.documentSelector = documentSelector.get<DocumentSelector>();
        srro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const SelectionRangeRegistrationOptions&
    srro)
    {
        if(srro.workDoneProgress.Present())
            data["workDoneProgress"] = srro.workDoneProgress.Value();
        if(srro.documentSelector.has_value())
            data["documentSelector"] = srro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(srro.id.Present())
            data["id"] = srro.id.Value();
    }
}