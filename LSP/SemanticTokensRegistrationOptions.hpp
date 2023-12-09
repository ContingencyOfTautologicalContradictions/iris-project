#pragma once
#include "Empty.hpp"
#include "Delta.hpp"
#include "DocumentSelector.hpp"
#include "SemanticTokensLegend.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SemanticTokensRegistrationOptions final
    {
    public:
        std::optional<DocumentSelector> documentSelector;

        Json::Field<bool> workDoneProgress;

        SemanticTokensLegend legend;

        Json::Field<std::variant<bool, Empty>> range;

        Json::Field<std::variant<bool, Delta>> full;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, SemanticTokensRegistrationOptions&);

    void to_json(nlohmann::json&, const SemanticTokensRegistrationOptions&);
}