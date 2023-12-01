#include "Notification.hpp"

namespace Iris::LSP
{
    template<class... T> auto Parameter(const nlohmann::json& param, const std
    ::string& method, Json::Field<std::vector<std::variant<T...>>>& params)
    noexcept -> void
    {
        std::variant<T...> variant;
        if(method == "$/cancelRequest")
            variant = param.get<CancelParams>();
        else if(method == "$/progress")
            variant = param.get<ProgressParams>();
        params.Value().push_back(variant);
    }

    void from_json(const nlohmann::json& data, Notification& n)
    {
        n.jsonrpc = data.at("jsonrpc").get<std::string>();
        n.method = data.at("method").get<std::string>();
        if(data.contains("params"))
        {
            n.params.Set();
            const nlohmann::json params = data.at("params");
            if(params.is_array())
                for(const nlohmann::json& param : params)
                    Parameter(param, n.method, n.params);
            else
                Parameter(params, n.method, n.params);
        }
    }

    void to_json(nlohmann::json& data, const Notification& n)
    {}
}