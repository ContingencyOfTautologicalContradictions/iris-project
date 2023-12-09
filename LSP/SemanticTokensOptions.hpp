#pragma once
#include "Empty.hpp"
#include "Delta.hpp"
#include "SemanticTokensLegend.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SemanticTokensOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        SemanticTokensLegend legend;

        Json::Field<std::variant<bool, Empty>> range;

        Json::Field<std::variant<bool, Delta>> full;
    };

    void from_json(const nlohmann::json&, SemanticTokensOptions&);

    void to_json(nlohmann::json&, const SemanticTokensOptions&);
}