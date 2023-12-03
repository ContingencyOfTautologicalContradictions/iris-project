#include "ShowMessageRequestClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    ShowMessageRequestClientCapabilities& smrcc)
    {
        smrcc.messageActionItem = Json::Field<MessageActionItem>(data,
        "messageActionItem");
    }

    void to_json(nlohmann::json& data, const
    ShowMessageRequestClientCapabilities& smrcc)
    {
        if(smrcc.messageActionItem.Present())
            data["messageActionItem"] = smrcc.messageActionItem.Value();
    }
}