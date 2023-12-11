#include "ServerInfo.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ServerInfo& si)
    {
        si.name = data.at("name").get<std::string>();
        si.version = Json::Field<std::string>(data, "version");
    }

    void to_json(nlohmann::json& data, const ServerInfo& si)
    {
        data["name"] = si.name;
        if(si.version.Present())
            data["version"] = si.version.Value();
    }
}