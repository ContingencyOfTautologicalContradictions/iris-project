#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CompletionList final
    {
    public:
        Json::Field<std::vector<std::string>> itemDefaults;
    };

    void from_json(const nlohmann::json&, CompletionList&);

    void to_json(nlohmann::json&, const CompletionList&);
}