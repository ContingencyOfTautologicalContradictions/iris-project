#pragma once
#include <cstdint>

namespace Iris
{
    class [[nodiscard]] Location final
    {
    public:
        std::uint64_t line, character;
    };
}