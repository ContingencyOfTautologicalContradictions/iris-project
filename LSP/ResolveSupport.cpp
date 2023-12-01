#include "ResolveSupport.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ResolveSupport& rs)
    {
        rs.properties = data.at("properties").get<std::vector<std::string>>();
    }
    
    void to_json(nlohmann::json& data, const ResolveSupport& rs)
    {
        data["properties"] = rs.properties;
    }
}