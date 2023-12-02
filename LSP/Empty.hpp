#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Empty final{};

    void from_json(const nlohmann::json&, Empty&){}

    void to_json(nlohmann::json&, const Empty&){}
}