#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DeleteFileOptions final
    {
    public:
        Json::Field<bool> recursive, ignoreIfNotExists;
    };

    void from_json(const nlohmann::json&, DeleteFileOptions&);

    void to_json(nlohmann::json&, const DeleteFileOptions&);
}