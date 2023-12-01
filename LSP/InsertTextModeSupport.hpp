#pragma once
#include "../JSON/Json.hpp"
#include "InsertTextMode.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InsertTextModeSupport final
    {
    public:
        std::vector<InsertTextMode> valueSet;
    };

    void from_json(const nlohmann::json&, InsertTextModeSupport&);

    void to_json(nlohmann::json&, const InsertTextModeSupport&);
}