#include "Requests.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Requests& r)
    {
        if(data.contains("range"))
        {
            r.range.Set();
            const nlohmann::json& range = data.at("range");
            if(range.is_boolean())
                r.range.Value() = range.get<bool>();
            else
                r.range.Value() = range.get<Empty>();
        }
        if(data.contains("full"))
        {
            r.full.Set();
            const nlohmann::json& full = data.at("full");
            if(full.is_boolean())
                r.full.Value() = full.get<bool>();
            else
                r.full.Value() = full.get<Delta>();
        }
    }

    void to_json(nlohmann::json& data, const Requests& r)
    {
        if(r.range.Present())
            std::visit([&](auto&& active)
            {
                data["range"] = active;
            }, r.range.Value());
        if(r.full.Present())
            std::visit([&](auto&& active)
            {
                data["full"] = active;
            }, r.full.Value());
    }
}