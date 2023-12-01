#include "SignatureInformation.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SignatureInformation& si)
    {
        si.documentationFormat = Json::Field<std::vector<MarkupKind>>(data,
        "documentationFormat");
        si.parameterInformation = Json::Field<ParameterInformation>(data,
        "parameterInformation");
        si.activeParameterSupport = Json::Field<bool>(data,
        "activeParameterSupport");
    }

    void to_json(nlohmann::json& data, const SignatureInformation& si)
    {
        if(si.documentationFormat.Present())
            data["documentationFormat"] = si.documentationFormat.Value();
        if(si.parameterInformation.Present())
            data["parameterInformation"] = si.parameterInformation.Value();
        if(si.activeParameterSupport.Present())
            data["activeParameterSupport"] = si.activeParameterSupport.Value();
    }
}