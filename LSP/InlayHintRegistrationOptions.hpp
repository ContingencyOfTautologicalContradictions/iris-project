#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InlayHintRegistrationOptions final
    {
    public:
        Json::Field<bool> workDoneProgress, resolveProvider;

        std::optional<DocumentSelector> documentSelector;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, InlayHintRegistrationOptions&);

    void to_json(nlohmann::json&, const InlayHintRegistrationOptions&);
}