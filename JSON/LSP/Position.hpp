#pragma once
#include "../Json.hpp"

namespace Iris::LSP
{
    enum class PositionEncoding : std::uint8_t
    {
        UTF8,
        UTF16,
        UTF32
    };

    [[nodiscard]] auto PositionEncodingKind(PositionEncoding pe) noexcept ->
    std::string
    {
        switch(pe)
        {
            using enum PositionEncoding;
            case UTF8:
                return "utf-8";
            case UTF16:
                return "utf-16";
            case UTF32:
                return "utf-32";
        }
    }

    class [[nodiscard]] Position final
    {
    public:
        std::uint64_t line, character;
    };

    void from_json(const nlohmann::json&, Position&);

    void to_json(nlohmann::json&, const Position&);
}