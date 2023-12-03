#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] MessageActionItem final
    {
    public:
        Json::Field<bool> additionalPropertiesSupport;
    };

    void from_json(const nlohmann::json&, MessageActionItem&);

    void to_json(nlohmann::json&, const MessageActionItem&);
}