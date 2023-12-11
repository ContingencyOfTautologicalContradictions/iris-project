#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] FileOperationPatternOptions final
    {
    public:
        Json::Field<bool> ignoreCase;
    };

    void from_json(const nlohmann::json&, FileOperationPatternOptions&);

    void to_json(nlohmann::json&, const FileOperationPatternOptions&);
}