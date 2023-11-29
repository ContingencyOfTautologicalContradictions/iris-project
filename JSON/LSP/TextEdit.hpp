#pragma once
#include "Range.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextEdit final
    {
    public:
        Range range;

        std::string newText;
    };

    void from_json(const nlohmann::json&, TextEdit&);

    void to_json(nlohmann::json&, const TextEdit&);
}