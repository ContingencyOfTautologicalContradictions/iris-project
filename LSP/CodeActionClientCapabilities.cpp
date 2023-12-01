#include "CodeActionClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CodeActionClientCapabilities&
    cacc)
    {
        cacc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        cacc.codeActionLiteralSupport = Json::Field<CodeActionLiteralSupport>(
        data, "codeActionLiteralSupport");
        cacc.isPreferredSupport = Json::Field<bool>(data, "isPreferredSupport")
        ;
        cacc.disabledSupport = Json::Field<bool>(data, "disabledSupport");
        cacc.dataSupport = Json::Field<bool>(data, "dataSupport");
        cacc.resolveSupport = Json::Field<ResolveSupport>(data,
        "resolveSupport");
        cacc.honorsChangeAnnotations = Json::Field<bool>(data,
        "honorsChangeAnnotations");
    }

    void to_json(nlohmann::json& data, const CodeActionClientCapabilities& cacc
    )
    {
        if(cacc.dynamicRegistration.Present())
            data["dynamicRegistration"] = cacc.dynamicRegistration.Value();
        if(cacc.codeActionLiteralSupport.Present())
            data["codeActionLiteralSupport"] = cacc.codeActionLiteralSupport.
            Value();
        if(cacc.isPreferredSupport.Present())
            data["isPreferredSupport"] = cacc.isPreferredSupport.Value();
        if(cacc.disabledSupport.Present())
            data["disabledSupport"] = cacc.disabledSupport.Value();
        if(cacc.dataSupport.Present())
            data["dataSupport"] = cacc.dataSupport.Value();
        if(cacc.resolveSupport.Present())
            data["resolveSupport"] = cacc.resolveSupport.Value();
        if(cacc.honorsChangeAnnotations.Present())
            data["honorsChangeAnnotations"] = cacc.honorsChangeAnnotations.
            Value();
    }
}