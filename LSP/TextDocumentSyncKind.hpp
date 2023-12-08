#pragma once
#include <cstdint>

namespace Iris::LSP
{
    enum class TextDocumentSyncKind : std::uint8_t
    {
        None = 0u,
        Full = 1u,
        Incremental = 2u
    };
}