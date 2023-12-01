#include "TextDocumentIdentifier.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TextDocumentIdentifier& tdi)
    {
        tdi.uri = data.at("uri").get<DocumentUri>();
    }

    void to_json(nlohmann::json& data, const TextDocumentIdentifier& tdi)
    {
        data["uri"] = tdi.uri;
    }
}