#include "MarkdownClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, MarkdownClientCapabilities& mcc)
    {
        mcc.parser = data.at("parser").get<std::string>();
        mcc.version = Json::Field<std::string>(data, "version");
        mcc.allowedTags = Json::Field<std::vector<std::string>>(data,
        "allowedTags");
    }

    void to_json(nlohmann::json& data, const MarkdownClientCapabilities& mcc)
    {
        data["parser"] = mcc.parser;
        if(mcc.version.Present())
            data["version"] = mcc.version.Value();
        if(mcc.allowedTags.Present())
            data["allowedTags"] = mcc.allowedTags.Value();
    }
}