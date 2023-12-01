#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ResolveSupport final
    {
    public:
        std::vector<std::string> properties;
    };

    void from_json(const nlohmann::json&, ResolveSupport&);

    void to_json(nlohmann::json&, const ResolveSupport&);
}