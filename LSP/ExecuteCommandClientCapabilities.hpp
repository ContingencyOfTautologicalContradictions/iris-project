#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ExecuteCommandClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, ExecuteCommandClientCapabilities&);

    void to_json(nlohmann::json&, const ExecuteCommandClientCapabilities&);
}