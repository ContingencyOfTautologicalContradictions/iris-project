#pragma once
#include "Location.hpp"

namespace Iris
{
    class [[nodiscard]] Range final
    {
    public:
        Location begin, end;
    };
}