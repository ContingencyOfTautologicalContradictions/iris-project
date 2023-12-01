#include "DocumentSymbolClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentSymbolClientCapabilities
    & dscc)
    {
        dscc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        dscc.symbolKind = Json::Field<SymbolKind>(data, "symbolKind");
        dscc.hierarchicalDocumentSymbolSupport = Json::Field<bool>(data,
        "hierarchicalDocumentSymbolSupport");
        dscc.tagSupport = Json::Field<SymbolTag>(data, "tagSupport");
        dscc.labelSupport = Json::Field<bool>(data, "labelSupport");
    }

    void to_json(nlohmann::json& data, const DocumentSymbolClientCapabilities&
    dscc)
    {
        if(dscc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dscc.dynamicRegistration.Value();
        if(dscc.symbolKind.Present())
            data["symbolKind"] = dscc.symbolKind.Value();
        if(dscc.hierarchicalDocumentSymbolSupport.Present())
            data["hierarchicalDocumentSymbolSupport"] = dscc.
            hierarchicalDocumentSymbolSupport.Value();
        if(dscc.tagSupport.Present())
            data["tagSupport"] = dscc.tagSupport.Value();
        if(dscc.labelSupport.Present())
            data["labelSupport"] = dscc.labelSupport.Value();
    }
}