#pragma once
#include "Location.hpp"
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    enum class DiagnosticSeverity : std::uint8_t
    {
        Error = 1u,
        Warning = 2u,
        Information = 3u,
        Hint = 4u
    };

    enum class DiagnosticTag : std::uint8_t
    {
        Unnecessary = 1u,
        Deprecated = 2u
    };

    class [[nodiscard]] CodeDescription final
    {
    public:
        URI href;
    };

    class [[nodiscard]] DiagnosticRelatedInformation final
    {
    public:
        Location location;

        std::string message;
    };

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

    void from_json(const nlohmann::json&, CodeDescription&);

    void to_json(nlohmann::json&, const CodeDescription&);

    void from_json(const nlohmann::json&, DiagnosticRelatedInformation&);

    void to_json(nlohmann::json&, const DiagnosticRelatedInformation&);

    void from_json(const nlohmann::json&, Diagnostic&);

    void to_json(nlohmann::json&, const Diagnostic&);
}