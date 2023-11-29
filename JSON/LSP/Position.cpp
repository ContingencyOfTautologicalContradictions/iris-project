#include "Position.hpp"

namespace Iris::LSP
{
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

    void from_json(const nlohmann::json& data, Position& p)
    {
        p.line = data.at("line").get<std::uint64_t>();
        p.character = data.at("character").get<std::uint64_t>();
    }

    void to_json(nlohmann::json& data, const Position& p)
    {
        data["line"] = p.line;
        data["character"] = p.character;
    }
}