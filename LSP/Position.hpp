#pragma once
#include "../JSON/Json.hpp"

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

    class [[nodiscard]] Position final
    {
    public:
        std::uint64_t line, character;
    };

    void from_json(const nlohmann::json&, Position&);

    void to_json(nlohmann::json&, const Position&);
}