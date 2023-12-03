#pragma once
#include "MessageActionItem.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ShowMessageRequestClientCapabilities final
    {
    public:
        Json::Field<MessageActionItem> messageActionItem;
    };

    void from_json(const nlohmann::json&, ShowMessageRequestClientCapabilities&
    );

    void to_json(nlohmann::json&, const ShowMessageRequestClientCapabilities&);
}