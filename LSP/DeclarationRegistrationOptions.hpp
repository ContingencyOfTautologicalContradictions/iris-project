#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DeclarationRegistrationOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        std::optional<DocumentSelector> documentSelector;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, DeclarationRegistrationOptions&);

    void to_json(nlohmann::json&, const DeclarationRegistrationOptions&);
}