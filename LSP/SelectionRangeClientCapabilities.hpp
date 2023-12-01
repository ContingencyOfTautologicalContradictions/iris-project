#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SelectionRangeClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, SelectionRangeClientCapabilities&);

    void to_json(nlohmann::json&, const SelectionRangeClientCapabilities&);
}