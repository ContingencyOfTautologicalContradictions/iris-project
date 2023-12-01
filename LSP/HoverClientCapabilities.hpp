#pragma once
#include "MarkupKind.hpp"
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] HoverClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Json::Field<std::vector<MarkupKind>> contentFormat;
    };

    void from_json(const nlohmann::json&, HoverClientCapabilities&);
    
    void to_json(nlohmann::json&, const HoverClientCapabilities&);
}