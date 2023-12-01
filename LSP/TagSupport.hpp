#pragma once
#include "../JSON/Json.hpp"
#include "CompletionItemTag.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TagSupport final
    {
    public:
        std::vector<CompletionItemTag> valueSet;
    };

    void from_json(const nlohmann::json&, TagSupport&);

    void to_json(nlohmann::json&, const TagSupport&);
}