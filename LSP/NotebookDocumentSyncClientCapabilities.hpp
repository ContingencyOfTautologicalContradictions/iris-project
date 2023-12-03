#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] NotebookDocumentSyncClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, executionSummarySupport;
    };

    void from_json(const nlohmann::json&,
    NotebookDocumentSyncClientCapabilities&);

    void to_json(nlohmann::json&, const NotebookDocumentSyncClientCapabilities&
    );
}