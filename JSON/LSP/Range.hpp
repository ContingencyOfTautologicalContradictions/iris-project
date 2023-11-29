#pragma once
#include "Position.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Range final
    {
    public:
        Position start, end;
    };

    void from_json(const nlohmann::json&, Range&);

    void to_json(nlohmann::json&, const Range&);
}