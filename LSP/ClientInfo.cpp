#include "ClientInfo.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ClientInfo& ci)
    {
        ci.name = data.at("name").get<std::string>();
        ci.version = Json::Field<std::string>(data, "version");
    }

    void to_json(nlohmann::json& data, const ClientInfo& ci)
    {
        data["name"] = ci.name;
        if(ci.version.Present())
            data["version"] = ci.version.Value();
    }
}