#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ImplementationClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, linkSupport;
    };

    void from_json(const nlohmann::json&, ImplementationClientCapabilities&);

    void to_json(nlohmann::json&, const ImplementationClientCapabilities&);
}