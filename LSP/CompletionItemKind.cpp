#include "CompletionItemKind.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CompletionItemKind& cik)
    {
        cik.valueSet = Json::Field<std::vector<ECompletionItemKind>>(data,
        "valueSet");
    }

    void to_json(nlohmann::json& data, const CompletionItemKind& cik)
    {
        if(cik.valueSet.Present())
            data["valueSet"] = cik.valueSet.Value();
    }
}