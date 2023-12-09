#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentFormattingOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, DocumentFormattingOptions&);

    void to_json(nlohmann::json&, const DocumentFormattingOptions&);
}