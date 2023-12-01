#pragma once
#include <cstdint>

namespace Iris::LSP
{
    enum class CompletionItemTag : std::uint8_t
    {
        Deprecated = 1u
    };
}