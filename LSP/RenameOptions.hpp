#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] RenameOptions final
    {
    public:
        Json::Field<bool> workDoneProgress, prepareProvider;
    };

    void from_json(const nlohmann::json&, RenameOptions&);

    void to_json(nlohmann::json&, const RenameOptions&);
}