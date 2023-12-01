#include "ChangeAnnotation.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ChangeAnnotation& ca)
    {
        ca.label = data.at("label").get<std::string>();
        ca.needsConfirmation = Json::Field<bool>(data, "needsConfirmation");
        ca.description = Json::Field<std::string>(data, "description");
    }

    void to_json(nlohmann::json& data, const ChangeAnnotation& ca)
    {
        data["label"] = ca.label;
        if(ca.needsConfirmation.Present())
            data["needsConfirmation"] = ca.needsConfirmation.Value();
        if(ca.description.Present())
            data["description"] = ca.description.Value();
    }
}