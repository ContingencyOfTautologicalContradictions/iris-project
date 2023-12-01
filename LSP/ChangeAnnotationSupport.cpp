#include "ChangeAnnotationSupport.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ChangeAnnotationSupport& cas)
    {
        cas.groupsOnLabel = Json::Field<bool>(data, "groupsOnLabel");
    }

    void to_json(nlohmann::json& data, const ChangeAnnotationSupport& cas)
    {
        if(cas.groupsOnLabel.Present())
            data["groupsOnLabel"] = cas.groupsOnLabel.Value();
    }
}