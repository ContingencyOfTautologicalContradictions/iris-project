#include "CodeActionKind.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CodeActionKind& cak)
    {
        cak.valueSet = data.at("valueSet").get<std::vector<std::string>>();
    }

    void to_json(nlohmann::json& data, const CodeActionKind& cak)
    {
        data["valueSet"] = cak.valueSet;
    }
}