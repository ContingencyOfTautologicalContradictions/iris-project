#pragma once
#include "../JSON/Field.hpp"
#include "ResolveSupport.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InlayHintClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Json::Field<ResolveSupport> resolveSupport;
    };

    void from_json(const nlohmann::json&, InlayHintClientCapabilities&);

    void to_json(nlohmann::json&, const InlayHintClientCapabilities&);
}