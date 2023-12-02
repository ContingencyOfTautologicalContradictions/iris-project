#include "Delta.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Delta& d)
    {
        d.delta = Json::Field<bool>(data, "delta");
    }

    void to_json(nlohmann::json& data, const Delta& d)
    {
        if(d.delta.Present())
            data["delta"] = d.delta.Value();
    }
}