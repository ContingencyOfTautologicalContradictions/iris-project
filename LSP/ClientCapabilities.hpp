#pragma once
#include "Window.hpp"
#include "General.hpp"
#include "Workspace.hpp"
#include "TextDocumentClientCapabilities.hpp"
#include "NotebookDocumentClientCapabilities.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ClientCapabilities final
    {
    public:
        Json::Field<Workspace> workspace;

        Json::Field<TextDocumentClientCapabilities> textDocument;

        Json::Field<NotebookDocumentClientCapabilities> notebookDocument;

        Json::Field<Window> window;

        Json::Field<General> general;

        Json::Field<std::variant<bool, std::int64_t, std::string>> experimental
        ;
    };

    void from_json(const nlohmann::json&, ClientCapabilities&);

    void to_json(nlohmann::json&, const ClientCapabilities&);
}