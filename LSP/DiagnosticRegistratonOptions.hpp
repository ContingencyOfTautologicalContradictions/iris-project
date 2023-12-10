#pragma once
#include "DocumentSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DiagnosticRegistrationOptions final
    {
    public:
        std::optional<DocumentSelector> documentSelector;

        Json::Field<bool> workDoneProgress;

        Json::Field<std::string> identifier;

        bool interFileDependencies, workspaceDiagnostics;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, DiagnosticRegistrationOptions&);

    void to_json(nlohmann::json&, const DiagnosticRegistrationOptions&);
}