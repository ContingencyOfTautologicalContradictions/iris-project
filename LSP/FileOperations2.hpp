#pragma once
#include "FileOperationRegistrationOptions.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FileOperations2 final
    {
    public:
        Json::Field<FileOperationRegistrationOptions> didCreate, willCreate,
        didRename, willRename, didDelete, willDelete;
    };

    void from_json(const nlohmann::json&, FileOperations2&);

    void to_json(nlohmann::json&, const FileOperations2&);
}