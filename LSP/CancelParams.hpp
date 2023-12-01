#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CancelParams final
    {
    public:
        std::variant<std::int64_t, std::string> id;
    };

    void from_json(const nlohmann::json&, CancelParams&);
}