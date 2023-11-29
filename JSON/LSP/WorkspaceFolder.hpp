#pragma once
#include "URI.hpp"
#include "../Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkspaceFolder final
    {
    public:
        URI uri;

        std::string name;
    };

    void from_json(const nlohmann::json&, WorkspaceFolder&);

    void to_json(nlohmann::json&, const WorkspaceFolder&);
}