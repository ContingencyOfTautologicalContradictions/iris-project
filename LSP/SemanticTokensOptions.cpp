#include "SemanticTokensOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SemanticTokensOptions& sto)
    {
        sto.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        sto.legend = data.at("legend").get<SemanticTokensLegend>();
        if(data.contains("range"))
        {
            sto.range.Set();
            const nlohmann::json& range = data.at("range");
            if(range.is_boolean())
                sto.range.Value() = range.get<bool>();
            else
                sto.range.Value() = range.get<Empty>();
        }
        if(data.contains("full"))
        {
            sto.full.Set();
            const nlohmann::json& full = data.at("full");
            if(full.is_boolean())
                sto.full.Value() = full.get<bool>();
            else
                sto.full.Value() = full.get<Delta>();
        }
    }

    void to_json(nlohmann::json& data, const SemanticTokensOptions& sto)
    {
        if(sto.workDoneProgress.Present())
            data["workDoneProgress"] = sto.workDoneProgress.Value();
        data["legend"] = sto.legend;
        if(sto.range.Present())
            std::visit([&](auto&& active)
            {
                data["range"] = active;
            }, sto.range.Value());
        if(sto.full.Present())
            std::visit([&](auto&& active)
            {
                data["full"] = active;
            }, sto.full.Value());
    }
}