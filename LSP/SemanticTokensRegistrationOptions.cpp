#include "SemanticTokensRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    SemanticTokensRegistrationOptions& stro)
    {
        const nlohmann::json& documentSelector = data.at("documentSelector");
        if(not documentSelector.is_null())
            stro.documentSelector = documentSelector.get<DocumentSelector>();
        stro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        stro.legend = data.at("legend").get<SemanticTokensLegend>();
        if(data.contains("range"))
        {
            stro.range.Set();
            const nlohmann::json& range = data.at("range");
            if(range.is_boolean())
                stro.range.Value() = range.get<bool>();
            else
                stro.range.Value() = range.get<Empty>();
        }
        if(data.contains("full"))
        {
            stro.full.Set();
            const nlohmann::json& full = data.at("full");
            if(full.is_boolean())
                stro.full.Value() = full.get<bool>();
            else
                stro.full.Value() = full.get<Delta>();
        }
        stro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const SemanticTokensRegistrationOptions&
    stro)
    {
        if(stro.documentSelector.has_value())
            data["documentSelector"] = stro.documentSelector.value();
        else
            data["documentSelector"] = nullptr;
        if(stro.workDoneProgress.Present())
            data["workDoneProgress"] = stro.workDoneProgress.Value();
        data["legend"] = stro.legend;
        if(stro.range.Present())
            std::visit([&](auto&& active)
            {
                data["range"] = active;
            }, stro.range.Value());
        if(stro.full.Present())
            std::visit([&](auto&& active)
            {
                data["full"] = active;
            }, stro.full.Value());
        if(stro.id.Present())
            data["id"] = stro.id.Value();
    }
}