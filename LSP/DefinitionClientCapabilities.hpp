#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DefinitionClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, linkSupport;
    };

    void from_json(const nlohmann::json&, DefinitionClientCapabilities&);

    void to_json(nlohmann::json&, const DefinitionClientCapabilities&);
}