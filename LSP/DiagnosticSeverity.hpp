#pragma once
#include <cstdint>

namespace Iris::LSP
{
    enum class DiagnosticSeverity : std::uint8_t
    {
        Error = 1u,
        Warning = 2u,
        Information = 3u,
        Hint = 4u
    };
}