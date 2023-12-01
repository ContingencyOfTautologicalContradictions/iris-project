#pragma once
#include "SymbolTag.hpp"
#include "SymbolKind.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentSymbolClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Json::Field<SymbolKind> symbolKind;

        Json::Field<bool> hierarchicalDocumentSymbolSupport;

        Json::Field<SymbolTag> tagSupport;

        Json::Field<bool> labelSupport;
    };

    void from_json(const nlohmann::json&, DocumentSymbolClientCapabilities&);

    void to_json(nlohmann::json&, const DocumentSymbolClientCapabilities&);
}