#include "SignatureHelpClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SignatureHelpClientCapabilities&
    shcc)
    {
        shcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        shcc.signatureInformation = Json::Field<SignatureInformation>(data,
        "signatureInformation");
        shcc.contextSupport = Json::Field<bool>(data, "contextSupport");
    }

    void to_json(nlohmann::json& data, const SignatureHelpClientCapabilities&
    shcc)
    {
        if(shcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = shcc.dynamicRegistration.Value();
        if(shcc.signatureInformation.Present())
            data["signatureInformation"] = shcc.signatureInformation.Value();
        if(shcc.contextSupport.Present())
            data["contextSupport"] = shcc.contextSupport.Value();
    }
}