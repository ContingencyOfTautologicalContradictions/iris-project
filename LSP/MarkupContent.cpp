#include "MarkupContent.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, MarkupContent& mc)
    {
        mc.kind = data.at("kind").get<MarkupKind>();
        mc.value = data.at("value").get<std::string>();
    }

    void to_json(nlohmann::json& data, const MarkupContent& mc)
    {
        data["kind"] = mc.kind;
        data["value"] = mc.value;
    }
}