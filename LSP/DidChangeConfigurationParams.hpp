#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DidChangeConfigurationParams final
    {
    public:
        std::variant<bool, std::int64_t, std::string> settings;
    };

    void from_json(const nlohmann::json&, DidChangeConfigurationParams&);

    void to_json(nlohmann::json&, const DidChangeConfigurationParams&);
}