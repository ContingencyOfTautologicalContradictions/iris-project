#pragma once
#include "FileOperationPattern.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FileOperationFilter final
    {
    public:
        Json::Field<std::string> scheme;

        FileOperationPattern pattern;
    };

    void from_json(const nlohmann::json&, FileOperationFilter&);

    void to_json(nlohmann::json&, const FileOperationFilter&);
}