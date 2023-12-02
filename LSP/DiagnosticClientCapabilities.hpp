#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DiagnosticClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, relatedDocumentSupport;
    };

    void from_json(const nlohmann::json&, DiagnosticClientCapabilities&);

    void to_json(nlohmann::json&, const DiagnosticClientCapabilities&);
}