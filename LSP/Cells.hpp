#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Cells final
    {
    public:
        std::string language;
    };

    void from_json(const nlohmann::json&, Cells&);

    void to_json(nlohmann::json&, const Cells&);
}