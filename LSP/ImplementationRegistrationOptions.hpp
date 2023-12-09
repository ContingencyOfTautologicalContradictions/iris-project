#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ImplementationRegistrationOptions final
    {
    public:
        std::optional<DocumentSelector> documentSelector;

        Json::Field<bool> workDoneProgress;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, ImplementationRegistrationOptions&);

    void to_json(nlohmann::json&, const ImplementationRegistrationOptions&);
}