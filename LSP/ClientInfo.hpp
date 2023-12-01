#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ClientInfo final
    {
    public:
        std::string name;

        Json::Field<std::string> version;
    };

    void from_json(const nlohmann::json&, ClientInfo&);

    void to_json(nlohmann::json&, const ClientInfo&);
}