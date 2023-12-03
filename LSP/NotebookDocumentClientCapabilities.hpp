#pragma once
#include "NotebookDocumentSyncClientCapabilities.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] NotebookDocumentClientCapabilities final
    {
    public:
        NotebookDocumentSyncClientCapabilities synchronization;
    };

    void from_json(const nlohmann::json&, NotebookDocumentClientCapabilities&);

    void to_json(nlohmann::json&, const NotebookDocumentClientCapabilities&);
}