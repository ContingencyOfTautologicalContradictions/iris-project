#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] MonikerRegistrationOptions final
    {
    public:
        std::optional<DocumentSelector> documentSelector;

        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, MonikerRegistrationOptions&);

    void to_json(nlohmann::json&, const MonikerRegistrationOptions&);
}