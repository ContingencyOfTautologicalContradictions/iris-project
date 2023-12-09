#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentRangeFormattingOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, DocumentRangeFormattingOptions&);

    void to_json(nlohmann::json&, const DocumentRangeFormattingOptions&);
}