#include "DiagnosticTag.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DiagnosticTag& dt)
    {
        dt.valueSet = data.at("valueSet").get<std::vector<EDiagnosticTag>>();
    }

    void to_json(nlohmann::json& data, const DiagnosticTag& dt)
    {
        data["valueSet"] = dt.valueSet;
    }
}