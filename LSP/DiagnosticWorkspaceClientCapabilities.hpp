#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DiagnosticWorkspaceClientCapabilities final
    {
    public:
        Json::Field<bool> refreshSupport;
    };

    void from_json(const nlohmann::json&, DiagnosticWorkspaceClientCapabilities
    &);

    void to_json(nlohmann::json&, const DiagnosticWorkspaceClientCapabilities&)
    ;
}