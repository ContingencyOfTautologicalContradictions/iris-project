#pragma once
#include "FileOperationPatternKind.hpp"
#include "FileOperationPatternOptions.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FileOperationPattern final
    {
    public:
        std::string glob;

        Json::Field<FileOperationPatternKind> matches;

        Json::Field<FileOperationPatternOptions> options;
    };

    void from_json(const nlohmann::json&, FileOperationPattern&);

    void to_json(nlohmann::json&, const FileOperationPattern&);
}