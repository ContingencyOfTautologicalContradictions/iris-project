#include "DocumentOnTypeFormattingOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentOnTypeFormattingOptions&
    dotfo)
    {
        dotfo.firstTriggerCharacter = data.at("firstTriggerCharacter").get<std
        ::string>();
        dotfo.moreTriggerCharacter = Json::Field<std::string>(data,
        "moreTriggerCharacter");
    }

    void to_json(nlohmann::json& data, const DocumentOnTypeFormattingOptions&
    dotfo)
    {
        data["firstTriggerCharacter"] = dotfo.firstTriggerCharacter;
        if(dotfo.moreTriggerCharacter.Present())
            data["moreTriggerCharacter"] = dotfo.moreTriggerCharacter.Value();
    }
}