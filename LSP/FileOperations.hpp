#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FileOperations final
    {
    public:
        Json::Field<bool> dynamicRegistration, didCreate, willCreate, didRename
        , willRename, didDelete, willDelete;
    };

    void from_json(const nlohmann::json&, FileOperations&);

    void to_json(nlohmann::json&, const FileOperations&);
}