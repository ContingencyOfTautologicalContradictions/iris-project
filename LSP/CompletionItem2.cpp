#include "CompletionItem2.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CompletionItem2& ci)
    {
        ci.labelDetailsSupport = Json::Field<bool>(data, "labelDetailsSupport")
        ;
    }

    void to_json(nlohmann::json& data, const CompletionItem2& ci)
    {
        if(ci.labelDetailsSupport.Present())
            data["labelDetailsSupport"] = ci.labelDetailsSupport.Value();
    }
}