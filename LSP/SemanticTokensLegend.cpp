#include "SemanticTokensLegend.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SemanticTokensLegend& stl)
    {
        stl.tokenTypes = data.at("tokenTypes").get<std::vector<std::string>>();
        stl.tokenModifiers = data.at("tokenModifiers").get<std::vector<std::
        string>>();
    }

    void to_json(nlohmann::json& data, const SemanticTokensLegend& stl)
    {
        data["tokenTypes"] = stl.tokenTypes;
        data["tokenModifiers"] = stl.tokenModifiers;
    }
}