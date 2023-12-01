#include "CodeActionLiteralSupport.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CodeActionLiteralSupport& cals)
    {
        cals.codeActionKind = data.at("codeActionKind").get<CodeActionKind>();
    }

    void to_json(nlohmann::json& data, const CodeActionLiteralSupport& cals)
    {
        data["codeActionKind"] = cals.codeActionKind;
    }
}