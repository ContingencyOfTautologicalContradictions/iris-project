#pragma once
#include "Position.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Range final
    {
    public:
        Position start, end;

        bool isEmpty, isSingleLine;
    };

    void from_json(const nlohmann::json&, Range&);

    void to_json(nlohmann::json&, const Range&);
}