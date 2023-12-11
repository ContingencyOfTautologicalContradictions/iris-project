#pragma once
#include "ServerInfo.hpp"
#include "ServerCapabilities.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InitializeResult final
    {
    public:
        ServerCapabilities capabilities;

        Json::Field<ServerInfo> serverInfo;
    };

    void from_json(const nlohmann::json&, InitializeResult&);

    void to_json(nlohmann::json&, const InitializeResult&);
}