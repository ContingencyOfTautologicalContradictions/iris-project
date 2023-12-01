#pragma once
#include "../JSON/Field.hpp"
#include "ECompletionItemKind.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CompletionItemKind final
    {
    public:
        Json::Field<std::vector<ECompletionItemKind>> valueSet;
    };

    void from_json(const nlohmann::json&, CompletionItemKind&);

    void to_json(nlohmann::json&, const CompletionItemKind&);
}