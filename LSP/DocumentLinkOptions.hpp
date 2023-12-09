#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentLinkOptions final
    {
    public:
        Json::Field<bool> workDoneProgress, resolveProvider;
    };

    void from_json(const nlohmann::json&, DocumentLinkOptions&);

    void to_json(nlohmann::json&, const DocumentLinkOptions&);
}