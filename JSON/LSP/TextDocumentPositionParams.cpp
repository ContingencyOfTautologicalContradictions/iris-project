#include "TextDocumentPositionParams.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TextDocumentPositionParams& tdpp
    )
    {
        tdpp.textDocument = data.at("textDocument").get<TextDocumentIdentifier>
        ();
        tdpp.position = data.at("position").get<Position>();
    }

    void to_json(nlohmann::json& data, const TextDocumentPositionParams& tdpp)
    {
        data["textDocument"] = tdpp.textDocument;
        data["position"] = tdpp.position;
    }
}