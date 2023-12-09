#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CompletionItem2 final
    {
    public:
        Json::Field<bool> labelDetailsSupport;
    };

    void from_json(const nlohmann::json&, CompletionItem2&);

    void to_json(nlohmann::json&, const CompletionItem2&);
}