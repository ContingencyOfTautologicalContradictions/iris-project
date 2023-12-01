#pragma once
#include "MarkupKind.hpp"
#include "ParameterInformation.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SignatureInformation final
    {
    public:
        Json::Field<std::vector<MarkupKind>> documentationFormat;

        Json::Field<ParameterInformation> parameterInformation;

        Json::Field<bool> activeParameterSupport;
    };

    void from_json(const nlohmann::json&, SignatureInformation&);

    void to_json(nlohmann::json&, const SignatureInformation&);
}