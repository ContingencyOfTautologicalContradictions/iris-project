#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CodeActionKind final
    {
    public:
        std::vector<std::string> valueSet;
    };

    void from_json(const nlohmann::json&, CodeActionKind&);

    void to_json(nlohmann::json&, const CodeActionKind&);
}