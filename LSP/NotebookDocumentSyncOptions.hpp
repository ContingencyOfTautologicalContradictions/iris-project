#pragma once
#include "NotebookSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] NotebookDocumentSyncOptions final
    {
    public:
        std::vector<NotebookSelector> notebookSelector;

        Json::Field<bool> save;
    };

    void from_json(const nlohmann::json&, NotebookDocumentSyncOptions&);

    void to_json(nlohmann::json&, const NotebookDocumentSyncOptions&);
}