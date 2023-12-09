#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentColorOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;
    };

    void from_json(const nlohmann::json&, DocumentColorOptions&);

    void to_json(nlohmann::json&, const DocumentColorOptions&);
}