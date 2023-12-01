#pragma once
#include "../JSON/Json.hpp"
#include "EDiagnosticTag.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DiagnosticTag final
    {
    public:
        std::vector<EDiagnosticTag> valueSet;
    };

    void from_json(const nlohmann::json&, DiagnosticTag&);

    void to_json(nlohmann::json&, const DiagnosticTag&);
}