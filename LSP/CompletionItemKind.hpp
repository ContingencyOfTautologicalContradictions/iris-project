#pragma once
#include <cstdint>

namespace Iris::LSP
{
    enum class CompletionItemKind : std::uint8_t
    {
        Text = 1u,
        Method = 2u,
        Function = 3u,
        Constructor = 4u,
        Field = 5u,
        Variable = 6u,
        Class = 7u,
        Interface = 8u,
        Module = 9u,
        Property = 10u,
        Unit = 11u,
        Value = 12u,
        Enum = 13u,
        Keyword = 14u,
        Snippet = 15u,
        Color = 16u,
        File = 17u,
        Reference = 18u,
        Folder = 19u,
        EnumMember = 20u,
        Constant = 21u,
        Struct = 22u,
        Event = 23u,
        Operator = 24u,
        TypeParameter = 25u
    };
}