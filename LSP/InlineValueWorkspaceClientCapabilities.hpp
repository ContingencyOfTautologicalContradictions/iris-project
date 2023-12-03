#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InlineValueWorkspaceClientCapabilities final
    {
    public:
        Json::Field<bool> refreshSupport;
    };

    void from_json(const nlohmann::json&,
    InlineValueWorkspaceClientCapabilities&);

    void to_json(nlohmann::json&, const InlineValueWorkspaceClientCapabilities&
    );
}