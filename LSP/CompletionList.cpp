#include "CompletionList.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CompletionList& cl)
    {
        cl.itemDefaults = Json::Field<std::vector<std::string>>(data,
        "itemDefaults");
    }

    void to_json(nlohmann::json& data, const CompletionList& cl)
    {
        if(cl.itemDefaults.Present())
            data["itemDefaults"] = cl.itemDefaults.Value();
    }
}