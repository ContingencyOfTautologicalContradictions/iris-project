#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentLinkClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, tooltipSupport;
    };

    void from_json(const nlohmann::json&, DocumentLinkClientCapabilities&);

    void to_json(nlohmann::json&, const DocumentLinkClientCapabilities&);
}