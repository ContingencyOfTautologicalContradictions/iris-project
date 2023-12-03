#include "MessageActionItem.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, MessageActionItem& mai)
    {
        mai.additionalPropertiesSupport = Json::Field<bool>(data,
        "additionalPropertiesSupport");
    }

    void to_json(nlohmann::json& data, const MessageActionItem& mai)
    {
        if(mai.additionalPropertiesSupport.Present())
            data["additionalPropertiesSupport"] = mai.
            additionalPropertiesSupport.Value();
    }
}