#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentColorClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, DocumentColorClientCapabilities&);

    void to_json(nlohmann::json&, const DocumentColorClientCapabilities&);
}