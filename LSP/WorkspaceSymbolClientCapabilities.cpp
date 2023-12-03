#include "WorkspaceSymbolClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    WorkspaceSymbolClientCapabilities& wscc)
    {
        wscc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        wscc.symbolKind = Json::Field<SymbolKind>(data, "symbolKind");
        wscc.tagSupport = Json::Field<SymbolTag>(data, "tagSupport");
        wscc.resolveSupport = Json::Field<ResolveSupport>(data,
        "resolveSupport");
    }

    void to_json(nlohmann::json& data, const WorkspaceSymbolClientCapabilities&
    wscc)
    {
        if(wscc.dynamicRegistration.Present())
            data["dynamicRegistration"] = wscc.dynamicRegistration.Value();
        if(wscc.symbolKind.Present())
            data["symbolKind"] = wscc.symbolKind.Value();
        if(wscc.tagSupport.Present())
            data["tagSupport"] = wscc.tagSupport.Value();
        if(wscc.resolveSupport.Present())
            data["resolveSupport"] = wscc.resolveSupport.Value();
    }
}