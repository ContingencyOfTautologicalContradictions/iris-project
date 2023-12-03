#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CodeLensWorkspaceClientCapabilities final
    {
    public:
        Json::Field<bool> refreshSupport;
    };

    void from_json(const nlohmann::json&, CodeLensWorkspaceClientCapabilities&)
    ;

    void to_json(nlohmann::json&, const CodeLensWorkspaceClientCapabilities&);
}