#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ReferenceClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, ReferenceClientCapabilities&);

    void to_json(nlohmann::json&, const ReferenceClientCapabilities&);
}