#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] LinkedEditingRangeClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, LinkedEditingRangeClientCapabilities&
    );

    void to_json(nlohmann::json&, const LinkedEditingRangeClientCapabilities&);
}