#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TypeHierarchyRegistrationOptions final
    {
    public:
        std::optional<DocumentSelector> documentSelector;

        Json::Field<bool> workDoneProgress;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, TypeHierarchyRegistrationOptions&);

    void to_json(nlohmann::json&, const TypeHierarchyRegistrationOptions&);
}