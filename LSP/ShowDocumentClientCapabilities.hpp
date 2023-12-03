#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ShowDocumentClientCapabilities final
    {
    public:
        bool support;
    };

    void from_json(const nlohmann::json&, ShowDocumentClientCapabilities&);

    void to_json(nlohmann::json&, const ShowDocumentClientCapabilities&);
}