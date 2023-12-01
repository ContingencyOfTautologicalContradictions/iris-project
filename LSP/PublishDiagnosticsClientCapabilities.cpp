#include "PublishDiagnosticsClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    PublishDiagnosticsClientCapabilities& pdcc)
    {
        pdcc.relatedInformation = Json::Field<bool>(data, "relatedInformation")
        ;
        pdcc.tagSupport = Json::Field<DiagnosticTag>(data, "tagSupport");
        pdcc.versionSupport = Json::Field<bool>(data, "versionSupport");
        pdcc.codeDescriptionSupport = Json::Field<bool>(data,
        "codeDescriptionSupport");
        pdcc.dataSupport = Json::Field<bool>(data, "dataSupport");
    }

    void to_json(nlohmann::json& data, const
    PublishDiagnosticsClientCapabilities& pdcc)
    {
        if(pdcc.relatedInformation.Present())
            data["relatedInformation"] = pdcc.relatedInformation.Value();
        if(pdcc.tagSupport.Present())
            data["tagSupport"] = pdcc.tagSupport.Value();
        if(pdcc.versionSupport.Present())
            data["versionSupport"] = pdcc.versionSupport.Value();
        if(pdcc.codeDescriptionSupport.Present())
            data["codeDescriptionSupport"] = pdcc.codeDescriptionSupport.Value(
            );
        if(pdcc.dataSupport.Present())
            data["dataSupport"] = pdcc.dataSupport.Value();
    }
}