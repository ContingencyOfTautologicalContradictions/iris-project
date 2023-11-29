#include "Request.hpp"

namespace Iris::LSP
{
    template<class... T> auto Parameter(const nlohmann::json& param, const std
    ::string& method, Json::Field<std::vector<std::variant<T...>>>& params)
    noexcept -> void
    {
        std::variant<T...> variant;
        
        params.Value().push_back(variant);
    }

    void from_json(const nlohmann::json& data, Request& r)
    {
        r.jsonrpc = data.at("jsonrpc").get<std::string>();
        const nlohmann::json& id = data.at("id");
        if(id.is_string())
            r.id = id.get<std::string>();
        else
            r.id = id.get<std::int64_t>();
        r.method = data.at("method").get<std::string>();
        if(data.contains("params"))
        {
            r.params.Set();
            const nlohmann::json params = data.at("params");
            if(params.is_array())
                for(const nlohmann::json& param : params)
                    Parameter(param, r.method, r.params);
            else
                Parameter(params, r.method, r.params);
        }
    }

    void to_json(nlohmann::json& data, const Request& r)
    {}
}