#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Delta final
    {
    public:
        Json::Field<bool> delta;
    };

    void from_json(const nlohmann::json&, Delta&);

    void to_json(nlohmann::json&, const Delta&);
}