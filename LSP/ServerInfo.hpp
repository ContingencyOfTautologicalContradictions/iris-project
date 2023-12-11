#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ServerInfo final
    {
    public:
        std::string name;

        Json::Field<std::string> version;
    };

    void from_json(const nlohmann::json&, ServerInfo&);

    void to_json(nlohmann::json&, const ServerInfo&);
}