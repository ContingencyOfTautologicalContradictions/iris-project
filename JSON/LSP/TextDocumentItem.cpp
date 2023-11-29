#include "TextDocumentItem.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TextDocumentItem& tdi)
    {
        tdi.uri = data.at("uri").get<DocumentUri>();
        tdi.languageId = data.at("languageId").get<std::string>();
        tdi.version = data.at("version").get<std::int64_t>();
        tdi.text = data.at("text").get<std::string>();
    }

    void to_json(nlohmann::json& data, const TextDocumentItem& tdi)
    {
        data["uri"] = tdi.uri;
        data["languageId"] = tdi.languageId;
        data["version"] = tdi.version;
        data["text"] = tdi.text;
    }
}