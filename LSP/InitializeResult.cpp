#include "InitializeResult.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, InitializeResult& ir)
    {
        ir.capabilities = data.at("capabilities").get<ServerCapabilities>();
        ir.serverInfo = Json::Field<ServerInfo>(data, "serverInfo");
    }

    void to_json(nlohmann::json& data, const InitializeResult& ir)
    {
        data["capabilities"] = ir.capabilities;
        if(ir.serverInfo.Present())
            data["serverInfo"] = ir.serverInfo.Value();
    }
}