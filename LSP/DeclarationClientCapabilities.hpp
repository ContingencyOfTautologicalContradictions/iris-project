#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DeclarationClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, linkSupport;
    };

    void from_json(const nlohmann::json&, DeclarationClientCapabilities&);

    void to_json(nlohmann::json&, const DeclarationClientCapabilities&);
}