#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DefinitionOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, DefinitionOptions&);

    void to_json(nlohmann::json&, const DefinitionOptions&);
}