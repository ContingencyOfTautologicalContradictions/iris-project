#pragma once
#include "DiagnosticTag.hpp"
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] PublishDiagnosticsClientCapabilities final
    {
    public:
        Json::Field<bool> relatedInformation;

        Json::Field<DiagnosticTag> tagSupport;

        Json::Field<bool> versionSupport, codeDescriptionSupport, dataSupport;
    };

    void from_json(const nlohmann::json&, PublishDiagnosticsClientCapabilities&
    );

    void to_json(nlohmann::json&, const PublishDiagnosticsClientCapabilities&);
}