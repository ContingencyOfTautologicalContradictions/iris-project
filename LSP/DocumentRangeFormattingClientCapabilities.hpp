#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentRangeFormattingClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&,
    DocumentRangeFormattingClientCapabilities&);

    void to_json(nlohmann::json&, const
    DocumentRangeFormattingClientCapabilities&);
}