#include "Diagnostic.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Diagnostic& d)
    {
        d.range = data.at("range").get<Range>();
        d.severity = Json::Field<DiagnosticSeverity>(data, "severity");
        if(data.contains("code"))
        {
            d.code.Set();
            const nlohmann::json& code = data.at("code");
            if(code.is_number_integer())
                d.code.Value() = code.get<std::int64_t>();
            else
                d.code.Value() = code.get<std::string>();
        }
        d.codeDescription = Json::Field<CodeDescription>(data,
        "codeDescription");
        d.source = Json::Field<std::string>(data, "source");
        d.message = data.at("message").get<std::string>();
        d.tags = Json::Field<std::vector<EDiagnosticTag>>(data, "tags");
        d.relatedInformation = Json::Field<std::vector<
        DiagnosticRelatedInformation>>(data, "relatedInformation");
    }

    void to_json(nlohmann::json& data, const Diagnostic& d)
    {
        data["range"] = d.range;
        if(d.severity.Present())
            data["severity"] = d.severity.Value();
        if(d.code.Present())
            std::visit([&](auto&& active)
            {
                data["code"] = active;
            }, d.code.Value());
        if(d.codeDescription.Present())
            data["codeDescription"] = d.codeDescription.Value();
        if(d.source.Present())
            data["source"] = d.source.Value();
        data["message"] = d.message;
        if(d.tags.Present())
            data["tags"] = d.tags.Value();
        if(d.relatedInformation.Present())
            data["relatedInformation"] = d.relatedInformation.Value();
    }
}