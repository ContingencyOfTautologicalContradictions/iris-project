#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TypeDefinitionRegistrationOptions final
    {
    public:
        std::optional<DocumentSelector> documentSelector;

        Json::Field<bool> workDoneProgress;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, TypeDefinitionRegistrationOptions&);

    void to_json(nlohmann::json&, const TypeDefinitionRegistrationOptions&);
}