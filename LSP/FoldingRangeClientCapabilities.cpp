#include "FoldingRangeClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FoldingRangeClientCapabilities&
    frcc)
    {
        frcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        frcc.rangeLimit = Json::Field<std::uint64_t>(data, "rangeLimit");
        frcc.lineFoldingOnly = Json::Field<bool>(data, "lineFoldingOnly");
        frcc.foldingRangeKind = Json::Field<FoldingRangeKind>(data,
        "foldingRangeKind");
        frcc.foldingRange = Json::Field<FoldingRange>(data, "foldingRange");
    }

    void to_json(nlohmann::json& data, const FoldingRangeClientCapabilities&
    frcc)
    {
        if(frcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = frcc.dynamicRegistration.Value();
        if(frcc.rangeLimit.Present())
            data["rangeLimit"] = frcc.rangeLimit.Value();
        if(frcc.lineFoldingOnly.Present())
            data["lineFoldingOnly"] = frcc.lineFoldingOnly.Value();
        if(frcc.foldingRangeKind.Present())
            data["foldingRangeKind"] = frcc.foldingRangeKind.Value();
        if(frcc.foldingRange.Present())
            data["foldingRange"] = frcc.foldingRange.Value();
    }
}