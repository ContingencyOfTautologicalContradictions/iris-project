#include "ProgressParams.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ProgressParams& pp)
    {
       const nlohmann::json& token = data.at("token");
        if(token.is_string())
            pp.token = token.get<std::string>();
        else
            pp.token = token.get<std::int64_t>();
        pp.value = data.at("value").get<Progress>();
    }

    void to_json(nlohmann::json& data, const ProgressParams& pp)
    {
        std::visit([&](auto&& active)
        {
            data["token"] = active;
        }, pp.token);
        data["value"] = pp.value;
    }
}