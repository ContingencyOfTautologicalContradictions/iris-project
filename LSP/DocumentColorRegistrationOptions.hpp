#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentColorRegistrationOptions final
    {
    public:
        std::optional<DocumentSelector> documentSelector;

        Json::Field<std::string> id;

        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, DocumentColorRegistrationOptions&);

    void to_json(nlohmann::json&, const DocumentColorRegistrationOptions&);
}