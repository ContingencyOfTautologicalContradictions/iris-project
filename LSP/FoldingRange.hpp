#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FoldingRange final
    {
    public:
        Json::Field<bool> collapsedText;
    };

    void from_json(const nlohmann::json&, FoldingRange&);

    void to_json(nlohmann::json&, const FoldingRange&);
}