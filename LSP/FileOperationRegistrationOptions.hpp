#pragma once
#include "FileOperationFilter.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FileOperationRegistrationOptions final
    {
    public:
        std::vector<FileOperationFilter> filters;
    };

    void from_json(const nlohmann::json&, FileOperationRegistrationOptions&);

    void to_json(nlohmann::json&, const FileOperationRegistrationOptions&);
}