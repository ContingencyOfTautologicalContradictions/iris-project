#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InlineValueClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, InlineValueClientCapabilities&);

    void to_json(nlohmann::json&, const InlineValueClientCapabilities&);
}