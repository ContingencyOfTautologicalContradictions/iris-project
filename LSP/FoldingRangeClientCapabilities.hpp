#pragma once
#include "FoldingRange.hpp"
#include "FoldingRangeKind.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FoldingRangeClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Json::Field<std::uint64_t> rangeLimit;

        Json::Field<bool> lineFoldingOnly;

        Json::Field<FoldingRangeKind> foldingRangeKind;

        Json::Field<FoldingRange> foldingRange;
    };

    void from_json(const nlohmann::json&, FoldingRangeClientCapabilities&);

    void to_json(nlohmann::json&, const FoldingRangeClientCapabilities&);
}