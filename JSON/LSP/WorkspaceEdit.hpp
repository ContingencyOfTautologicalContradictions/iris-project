#pragma once
#include "CreateFile.hpp"
#include "RenameFile.hpp"
#include "DeleteFile.hpp"
#include "TextDocumentEdit.hpp"
#include "ChangeAnnotation.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkspaceEdit final
    {
    public:
        Json::Field<std::unordered_map<DocumentUri, std::vector<TextEdit>>>
        changes;

        Json::Field<std::vector<std::variant<TextDocumentEdit, CreateFile,
        RenameFile, DeleteFile>>> documentChanges;

        Json::Field<std::unordered_map<ChangeAnnotationIdentifier,
        ChangeAnnotation>> changeAnnotations;
    };

    void from_json(const nlohmann::json&, WorkspaceEdit&);

    void to_json(nlohmann::json&, const WorkspaceEdit&);
}