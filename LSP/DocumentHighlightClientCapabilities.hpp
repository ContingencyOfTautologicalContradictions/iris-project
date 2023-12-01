#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentHighlightClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&, DocumentHighlightClientCapabilities&)
    ;

    void to_json(nlohmann::json&, const DocumentHighlightClientCapabilities&);
}