#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] InlayHintOptions final
    {
    public:
        Json::Field<bool> workDoneProgress, resolveProvider;
    };

    void from_json(const nlohmann::json&, InlayHintOptions&);

    void to_json(nlohmann::json&, const InlayHintOptions&);
}