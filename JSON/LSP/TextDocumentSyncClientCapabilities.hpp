#pragma once
#include "../Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextDocumentSyncClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, willSave, willSaveWaitUntil,
        didSave;
    };

    void from_json(const nlohmann::json&, TextDocumentSyncClientCapabilities&);

    void to_json(nlohmann::json&, const TextDocumentSyncClientCapabilities&);
}