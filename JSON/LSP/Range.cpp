#include "Range.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Range& r)
    {
        r.start = data.at("start").get<Position>();
        r.end = data.at("end").get<Position>();
    }

    void to_json(nlohmann::json& data, const Range& r)
    {
        data["start"] = r.start;
        data["end"] = r.end;
    }
}