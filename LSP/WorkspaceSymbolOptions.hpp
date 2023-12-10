#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkspaceSymbolOptions final
    {
    public:
        Json::Field<bool> workDoneProgress, resolveProvider;
    };

    void from_json(const nlohmann::json&, WorkspaceSymbolOptions&);

    void to_json(nlohmann::json&, const WorkspaceSymbolOptions&);
}