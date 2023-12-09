#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ImplementationOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, ImplementationOptions&);

    void to_json(nlohmann::json&, const ImplementationOptions&);
}