#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InlayHintWorkspaceClientCapabilities final
    {
    public:
        Json::Field<bool> refreshSupport;
    };

    void from_json(const nlohmann::json&, InlayHintWorkspaceClientCapabilities&
    );

    void to_json(nlohmann::json&, const InlayHintWorkspaceClientCapabilities&);
}