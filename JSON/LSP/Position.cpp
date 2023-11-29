#include "Position.hpp"

namespace Iris::LSP
{
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