#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CodeLensClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, CodeLensClientCapabilities&);

    void to_json(nlohmann::json&, const CodeLensClientCapabilities&);
}