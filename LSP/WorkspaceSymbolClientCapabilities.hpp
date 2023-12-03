#pragma once
#include "SymbolTag.hpp"
#include "SymbolKind.hpp"
#include "ResolveSupport.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkspaceSymbolClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Json::Field<SymbolKind> symbolKind;

        Json::Field<SymbolTag> tagSupport;

        Json::Field<ResolveSupport> resolveSupport;
    };

    void from_json(const nlohmann::json&, WorkspaceSymbolClientCapabilities&);

    void to_json(nlohmann::json&, const WorkspaceSymbolClientCapabilities&);
}