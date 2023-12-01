#pragma once
#include "SignatureInformation.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SignatureHelpClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Json::Field<SignatureInformation> signatureInformation;

        Json::Field<bool> contextSupport;
    };

    void from_json(const nlohmann::json&, SignatureHelpClientCapabilities&);

    void to_json(nlohmann::json&, const SignatureHelpClientCapabilities&);
}