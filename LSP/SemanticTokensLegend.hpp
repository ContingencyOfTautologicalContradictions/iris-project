#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SemanticTokensLegend final
    {
    public:
        std::vector<std::string> tokenTypes, tokenModifiers;
    };

    void from_json(const nlohmann::json&, SemanticTokensLegend&);

    void to_json(nlohmann::json&, const SemanticTokensLegend&);
}