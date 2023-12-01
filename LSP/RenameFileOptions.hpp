#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] RenameFileOptions final
    {
    public:
        Json::Field<bool> overwrite, ignoreIfExists;
    };

    void from_json(const nlohmann::json&, RenameFileOptions&);

    void to_json(nlohmann::json&, const RenameFileOptions&);
}