#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DiagnosticOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        Json::Field<std::string> identifier;

        bool interFileDependencies, workspaceDiagnostics;
    };

    void from_json(const nlohmann::json&, DiagnosticOptions&);

    void to_json(nlohmann::json&, const DiagnosticOptions&);
}