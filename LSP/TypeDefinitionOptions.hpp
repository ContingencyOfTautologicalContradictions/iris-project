#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TypeDefinitionOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, TypeDefinitionOptions&);

    void to_json(nlohmann::json&, const TypeDefinitionOptions&);
}