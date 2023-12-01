#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Request final
    {
    public:
        std::string jsonrpc;

        std::variant<std::int64_t, std::string> id;

        std::string method;

        Json::Field<std::vector<std::variant<bool>>> params;
    };

    void from_json(const nlohmann::json&, Request&);

    void to_json(nlohmann::json&, const Request&);
}