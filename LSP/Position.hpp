#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Position final
    {
    public:
        std::uint64_t line, character;
    };

    void from_json(const nlohmann::json&, Position&);

    void to_json(nlohmann::json&, const Position&);
}