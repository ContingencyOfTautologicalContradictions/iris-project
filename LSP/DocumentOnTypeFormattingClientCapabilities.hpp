#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentOnTypeFormattingClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&,
    DocumentOnTypeFormattingClientCapabilities&);

    void to_json(nlohmann::json&, const
    DocumentOnTypeFormattingClientCapabilities&);
}