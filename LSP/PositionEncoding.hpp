#pragma once
#include <string>

namespace Iris::LSP
{
    enum class PositionEncoding : std::uint8_t
    {
        UTF8,
        UTF16,
        UTF32
    };

    [[nodiscard]] auto PositionEncodingKind(PositionEncoding) noexcept -> std::
    string;
}