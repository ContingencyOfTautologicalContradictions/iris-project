#pragma once
#include "../JSON/Field.hpp"
#include "DiagnosticTag.hpp"
#include "CodeDescription.hpp"
#include "DiagnosticSeverity.hpp"
#include "DiagnosticRelatedInformation.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Diagnostic final
    {
    public:
        Range range;

        Json::Field<DiagnosticSeverity> severity;

        Json::Field<std::variant<std::int64_t, std::string>> code;

        Json::Field<CodeDescription> codeDescription;

        Json::Field<std::string> source;

        std::string message;

        Json::Field<std::vector<DiagnosticTag>> tags;

        Json::Field<std::vector<DiagnosticRelatedInformation>>
        relatedInformation;
    };

    void from_json(const nlohmann::json&, Diagnostic&);

    void to_json(nlohmann::json&, const Diagnostic&);
}