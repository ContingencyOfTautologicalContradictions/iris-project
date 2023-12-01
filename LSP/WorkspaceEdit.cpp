#include "WorkspaceEdit.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, WorkspaceEdit& we)
    {
        we.changes = Json::Field<std::unordered_map<DocumentUri, std::vector<
        TextEdit>>>(data, "changes");
        if(data.contains("documentChanges"))
        {
            we.documentChanges.Set();
            const nlohmann::json& documentChanges = data.at("documentChanges");
            for(const nlohmann::json& documentChange : documentChanges)
            {
                if(documentChange.contains("kind"))
                {
                    const std::string kind = documentChange.at("kind").get<std
                    ::string>();
                    if(kind == "create")
                        we.documentChanges.Value().push_back(documentChange.get
                        <CreateFile>());
                    else if(kind == "rename")
                        we.documentChanges.Value().push_back(documentChange.get
                        <RenameFile>());
                    else
                        we.documentChanges.Value().push_back(documentChange.get
                        <DeleteFile>());
                }
                else
                    we.documentChanges.Value().push_back(documentChange.get<
                    TextDocumentEdit>());
            }
        }
        we.changeAnnotations = Json::Field<std::unordered_map<
        ChangeAnnotationIdentifier, ChangeAnnotation>>(data,
        "changeAnnotations");
    }

    [[nodiscard]] auto jsonify(const std::vector<std::variant<TextDocumentEdit,
    CreateFile, RenameFile, DeleteFile>>& documentChanges) noexcept -> nlohmann
    ::json
    {
        nlohmann::json data;
        for(const std::variant<TextDocumentEdit, CreateFile, RenameFile,
        DeleteFile>& documentChange : documentChanges)
            std::visit([&](auto&& active)
            {
                data.push_back(active);
            }, documentChange);
        return data;
    }

    void to_json(nlohmann::json& data, const WorkspaceEdit& we)
    {
        if(we.changes.Present())
            data["changes"] = we.changes.Value();
        if(we.documentChanges.Present())
            data["documentChanges"] = jsonify(we.documentChanges.Value());
        if(we.changeAnnotations.Present())
            data["changeAnnotations"] = we.changeAnnotations.Value();
    }
}