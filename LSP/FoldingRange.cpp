#include "FoldingRange.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FoldingRange& fr)
    {
        fr.collapsedText = Json::Field<bool>(data, "collapsedText");
    }

    void to_json(nlohmann::json& data, const FoldingRange& fr)
    {
        if(fr.collapsedText.Present())
            data["collapsedText"] = fr.collapsedText.Value();
    }
}