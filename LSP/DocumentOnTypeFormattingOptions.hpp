#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentOnTypeFormattingOptions final
    {
    public:
        std::string firstTriggerCharacter;

        Json::Field<std::string> moreTriggerCharacter;
    };

    void from_json(const nlohmann::json&, DocumentOnTypeFormattingOptions&);

    void to_json(nlohmann::json&, const DocumentOnTypeFormattingOptions&);
}