#include "FoldingRangeKind.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FoldingRangeKind& frk)
    {
        frk.valueSet = Json::Field<std::vector<std::string>>(data, "valueSet");
    }

    void to_json(nlohmann::json& data, const FoldingRangeKind& frk)
    {
        if(frk.valueSet.Present())
            data["valueSet"] = frk.valueSet.Value();
    }
}