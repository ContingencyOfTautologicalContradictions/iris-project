#pragma once
#include "../Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentFilter final
    {
    public:
        Json::Field<std::string> language, scheme, pattern;
    };

    void from_json(const nlohmann::json&, DocumentFilter&);

    void to_json(nlohmann::json&, const DocumentFilter&);
}