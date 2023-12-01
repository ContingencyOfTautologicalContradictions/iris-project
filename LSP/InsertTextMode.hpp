#pragma once
#include <cstdint>

namespace Iris::LSP
{
    enum class InsertTextMode : std::uint8_t
    {
        asIs = 1,
        adjustIndentation = 2
    };
}