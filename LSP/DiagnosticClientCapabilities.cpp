#include "DiagnosticClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DiagnosticClientCapabilities&
    dcc)
    {
        dcc.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration"
        );
        dcc.relatedDocumentSupport = Json::Field<bool>(data,
        "relatedDocumentSupport");
    }

    void to_json(nlohmann::json& data, const DiagnosticClientCapabilities& dcc)
    {
        if(dcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = dcc.dynamicRegistration.Value();
        if(dcc.relatedDocumentSupport.Present())
            data["relatedDocumentSupport"] = dcc.relatedDocumentSupport.Value()
            ;
    }
}