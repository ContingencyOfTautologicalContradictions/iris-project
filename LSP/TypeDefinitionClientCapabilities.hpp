#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TypeDefinitionClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, linkSupport;
    };

    void from_json(const nlohmann::json&, TypeDefinitionClientCapabilities&);

    void to_json(nlohmann::json&, const TypeDefinitionClientCapabilities&);
}