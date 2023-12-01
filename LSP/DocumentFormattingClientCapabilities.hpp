#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentFormattingClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, DocumentFormattingClientCapabilities&
    );

    void to_json(nlohmann::json&, const DocumentFormattingClientCapabilities&);
}