#include "Cells.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Cells& c)
    {
        c.language = data.at("language").get<std::string>();
    }

    void to_json(nlohmann::json& data, const Cells& c)
    {
        data["language"] = c.language;
    }
}