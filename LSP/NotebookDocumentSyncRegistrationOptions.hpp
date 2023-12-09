#pragma once
#include "NotebookSelector.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] NotebookDocumentSyncRegistrationOptions final
    {
    public:
        std::vector<NotebookSelector> notebookSelector;

        Json::Field<bool> save;

        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, NotebookDocumentSyncRegistrationOptions&);

    void to_json(nlohmann::json&, const NotebookDocumentSyncRegistrationOptions&);
}