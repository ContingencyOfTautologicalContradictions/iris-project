#include "SemanticTokensClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, SemanticTokensClientCapabilities
    & stcc)
    {
        stcc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        stcc.requests = data.at("requests").get<Requests>();
        stcc.tokenTypes = data.at("tokenTypes").get<std::vector<std::string>>()
        ;
        stcc.tokenModifiers = data.at("tokenModifiers").get<std::vector<std::
        string>>();
        stcc.tokenFormats = data.at("tokenFormats").get<std::vector<TokenFormat
        >>();
        stcc.overlappingTokenSupport = Json::Field<bool>(data,
        "overlappingTokenSupport");
        stcc.multilineTokenSupport = Json::Field<bool>(data,
        "multilineTokenSupport");
        stcc.serverCancelSupport = Json::Field<bool>(data,
        "serverCancelSupport");
        stcc.augmentsSyntaxTokens = Json::Field<bool>(data,
        "augmentsSyntaxTokens");
    }
    
    void to_json(nlohmann::json& data, const SemanticTokensClientCapabilities&
    stcc)
    {
        if(stcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = stcc.dynamicRegistration.Value();
        data["requests"] = stcc.requests;
        data["tokenTypes"] = stcc.tokenTypes;
        data["tokenModifiers"] = stcc.tokenModifiers;
        data["tokenFormats"] = stcc.tokenFormats;
        if(stcc.overlappingTokenSupport.Present())
            data["overlappingTokenSupport"] = stcc.overlappingTokenSupport.
            Value();
        if(stcc.multilineTokenSupport.Present())
            data["multilineTokenSupport"] = stcc.multilineTokenSupport.Value();
        if(stcc.serverCancelSupport.Present())
            data["serverCancelSupport"] = stcc.serverCancelSupport.Value();
        if(stcc.augmentsSyntaxTokens.Present())
            data["augmentsSyntaxTokens"] = stcc.augmentsSyntaxTokens.Value();
    }
}