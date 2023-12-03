#include "DidChangeConfigurationParams.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DidChangeConfigurationParams&
    dccp)
    {
        const nlohmann::json& settings = data.at("settings");
        if(settings.is_boolean())
            dccp.settings = settings.get<bool>();
        else if(settings.is_number_integer())
            dccp.settings = settings.get<std::int64_t>();
        else if(settings.is_string())
            dccp.settings = settings.get<std::string>();
    }

    [[nodiscard]] auto jsonify(const std::variant<bool, std::int64_t, std::
    string>& settings) noexcept -> nlohmann::json
    {
        nlohmann::json data;
        std::visit([&](auto&& active)
        {
            data = active;
        }, settings);
        return data;
    }

    void to_json(nlohmann::json& data, const DidChangeConfigurationParams& dccp
    )
    {
        data["settings"] = jsonify(dccp.settings);
    }
}