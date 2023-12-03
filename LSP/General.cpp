#include "General.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, General& g)
    {
        g.staleRequestSupport = Json::Field<StaleRequestSupport>(data,
        "staleRequestSupport");
        g.regularExpressions = Json::Field<RegularExpressionsClientCapabilities
        >(data, "regularExpressions");
        g.markdown = Json::Field<MarkdownClientCapabilities>(data, "markdown");
        g.positionEncodings = Json::Field<std::vector<PositionEncodingKind>>(
        data, "positionEncodings");
    }

    void to_json(nlohmann::json& data, const General& g)
    {
        if(g.staleRequestSupport.Present())
            data["staleRequestSupport"] = g.staleRequestSupport.Value();
        if(g.regularExpressions.Present())
            data["regularExpressions"] = g.regularExpressions.Value();
        if(g.markdown.Present())
            data["markdown"] = g.markdown.Value();
        if(g.positionEncodings.Present())
            data["positionEncodings"] = g.positionEncodings.Value();
    }
}