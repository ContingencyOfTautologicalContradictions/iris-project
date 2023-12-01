#pragma once
#include <cstdint>

namespace Iris::LSP
{
    enum class InsertTextMode : std::uint8_t
    {
        asIs = 1u,
        adjustIndentation = 2u
    };
}