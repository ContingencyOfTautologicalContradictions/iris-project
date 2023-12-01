#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CreateFileOptions final
    {
    public:
        Json::Field<bool> overwrite, ignoreIfExists;
    };

    void from_json(const nlohmann::json&, CreateFileOptions&);

    void to_json(nlohmann::json&, const CreateFileOptions&);
}