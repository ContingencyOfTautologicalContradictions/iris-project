#include "TagSupport.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TagSupport& ts)
    {
        ts.valueSet = data.at("valueSet").get<std::vector<CompletionItemTag>>();
    }

    void to_json(nlohmann::json& data, const TagSupport& ts)
    {
        data["valueSet"] = ts.valueSet;
    }
}