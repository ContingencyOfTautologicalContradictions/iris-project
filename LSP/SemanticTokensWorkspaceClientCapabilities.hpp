#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SemanticTokensWorkspaceClientCapabilities final
    {
    public:
        Json::Field<bool> refreshSupport;
    };

    void from_json(const nlohmann::json&,
    SemanticTokensWorkspaceClientCapabilities&);

    void to_json(nlohmann::json&, const
    SemanticTokensWorkspaceClientCapabilities&);
}