#pragma once
#include "Requests.hpp"
#include "TokenFormat.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SemanticTokensClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Requests requests;

        std::vector<std::string> tokenTypes, tokenModifiers;

        std::vector<TokenFormat> tokenFormats;

        Json::Field<bool> overlappingTokenSupport, multilineTokenSupport,
        serverCancelSupport, augmentsSyntaxTokens;
    };

    void from_json(const nlohmann::json&, SemanticTokensClientCapabilities&);

    void to_json(nlohmann::json&, const SemanticTokensClientCapabilities&);
}