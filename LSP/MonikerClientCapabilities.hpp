#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] MonikerClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, MonikerClientCapabilities&);

    void to_json(nlohmann::json&, const MonikerClientCapabilities&);
}