#pragma once
#include "StaleRequestSupport.hpp"
#include "PositionEncodingKind.hpp"
#include "MarkdownClientCapabilities.hpp"
#include "RegularExpressionsClientCapabilities.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] General final
    {
    public:
        Json::Field<StaleRequestSupport> staleRequestSupport;

        Json::Field<RegularExpressionsClientCapabilities> regularExpressions;

        Json::Field<MarkdownClientCapabilities> markdown;

        Json::Field<std::vector<PositionEncodingKind>> positionEncodings;
    };

    void from_json(const nlohmann::json&, General&);

    void to_json(nlohmann::json&, const General&);
}