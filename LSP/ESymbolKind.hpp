#pragma once
#include <cstdint>

namespace Iris::LSP
{
    enum class ESymbolKind : std::uint8_t
    {
        File = 1u,
        Module = 2u,
        Namespace = 3u,
        Package = 4u,
        Class = 5u,
        Method = 6u,
        Property = 7u,
        Field = 8u,
        Constructor = 9u,
        Enum = 10u,
        Interface = 11u,
        Function = 12u,
        Variable = 13u,
        Constant = 14u,
        String = 15u,
        Number = 16u,
        Boolean = 17u,
        Array = 18u,
        Object = 19u,
        Key = 20u,
        Null = 21u,
        EnumMember = 22u,
        Struct = 23u,
        Event = 24u,
        Operator = 25u,
        TypeParameter = 26u
    };
}