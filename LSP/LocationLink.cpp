#include "LocationLink.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, LocationLink& ll)
    {
        ll.originSelectionRange = Json::Field<Range>(data,
        "originSelectionRange");
        ll.targetUri = data.at("targetUri").get<DocumentUri>();
        ll.targetRange = data.at("targetRange").get<Range>();
        ll.targetSelectionRange = data.at("targetSelectionRange").get<Range>();
    }

    void to_json(nlohmann::json& data, const LocationLink& ll)
    {
        if(ll.originSelectionRange.Present())
            data["originSelectionRange"] = ll.originSelectionRange.Value();
        data["targetUri"] = ll.targetUri;
        data["targetRange"] = ll.targetRange;
        data["targetSelectionRange"] = ll.targetSelectionRange;
    }
}