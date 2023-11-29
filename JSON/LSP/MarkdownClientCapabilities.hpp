#pragma once
#include "../Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] MarkdownClientCapabilities final
    {
    public:
        std::string parser;

        Json::Field<std::string> version;

        Json::Field<std::vector<std::string>> allowedTags;
    };

    void from_json(const nlohmann::json&, MarkdownClientCapabilities&);

    void to_json(nlohmann::json&, const MarkdownClientCapabilities&);
}