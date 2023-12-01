#include "TextDocumentEdit.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TextDocumentEdit& tde)
    {
        tde.textDocument = data.at("textDocument").get<
        OptionalVersionedTextDocumentIdentifier>();
        const nlohmann::json edits = data.at("edits");
        for(const nlohmann::json& edit : edits)
        {
            if(edit.contains("annotationId"))
                tde.edits.push_back(edit.get<AnnotatedTextEdit>());
            else
                tde.edits.push_back(edit.get<TextEdit>());
        }
    }

    void to_json(nlohmann::json& data, const std::vector<std::variant<TextEdit,
    AnnotatedTextEdit>>& vs)
    {
        for(const std::variant<TextEdit, AnnotatedTextEdit>& v : vs)
            std::visit([&](auto&& active)
            {
                data.push_back(active);
            }, v);
    }

    void to_json(nlohmann::json& data, const TextDocumentEdit& tde)
    {
        data["textDocument"] = tde.textDocument;
        data["edits"] = tde.edits;
    }
}