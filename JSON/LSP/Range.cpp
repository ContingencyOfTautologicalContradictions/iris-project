#include "Range.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Range& r)
    {
        r.start = data.at("start").get<Position>();
        r.end = data.at("end").get<Position>();
        r.isEmpty = data.at("isEmpty").get<bool>();
        r.isSingleLine = data.at("isSingleLine").get<bool>();
    }

    void to_json(nlohmann::json& data, const Range& r)
    {
        data["start"] = r.start;
        data["end"] = r.end;
        data["isEmpty"] = r.isEmpty;
        data["isSingleLine"] = r.isSingleLine;
    }
}