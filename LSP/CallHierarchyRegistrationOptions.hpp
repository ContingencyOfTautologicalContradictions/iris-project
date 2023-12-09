#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CallHierarchyRegistrationOptions final
    {
    public:
        std::optional<DocumentSelector> documentSelector;

        Json::Field<bool> workDoneProgress;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, CallHierarchyRegistrationOptions&);

    void to_json(nlohmann::json&, const CallHierarchyRegistrationOptions&);
}