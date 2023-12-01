#pragma once
#include <cstdint>

namespace Iris::LSP
{
    enum class EDiagnosticTag : std::uint8_t
    {
        Unnecessary = 1u,
        Deprecated = 2u
    };
}