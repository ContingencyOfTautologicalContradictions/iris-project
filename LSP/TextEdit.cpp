#include "TextEdit.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TextEdit& te)
    {
        te.range = data.at("range").get<Range>();
        te.newText = data.at("newText").get<std::string>();
    }

    void to_json(nlohmann::json& data, const TextEdit& te)
    {
        data["range"] = te.range;
        data["newText"] = te.newText;
    }
}