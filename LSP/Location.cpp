#include "Location.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Location& l)
    {
        l.uri = data.at("uri").get<DocumentUri>();
        l.range = data.at("range").get<Range>();
    }

    void to_json(nlohmann::json& data, const Location& l)
    {
        data["uri"] = l.uri;
        data["range"] = l.range;
    }
}