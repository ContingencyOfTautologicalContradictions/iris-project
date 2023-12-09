#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CodeLensOptions final
    {
    public:
        Json::Field<bool> workDoneProgress, resolveProvider;
    };

    void from_json(const nlohmann::json&, CodeLensOptions&);

    void to_json(nlohmann::json&, const CodeLensOptions&);
}