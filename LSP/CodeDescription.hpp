#pragma once
#include "URI.hpp"
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CodeDescription final
    {
    public:
        URI href;
    };

    void from_json(const nlohmann::json&, CodeDescription&);

    void to_json(nlohmann::json&, const CodeDescription&);
}