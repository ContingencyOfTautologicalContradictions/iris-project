#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentHighlightOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, DocumentHighlightOptions&);

    void to_json(nlohmann::json&, const DocumentHighlightOptions&);
}