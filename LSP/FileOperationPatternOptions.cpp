#include "FileOperationPatternOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FileOperationPatternOptions&
    fopo)
    {
        fopo.ignoreCase = Json::Field<bool>(data, "ignoreCase");
    }

    void to_json(nlohmann::json& data, const FileOperationPatternOptions& fopo)
    {
        if(fopo.ignoreCase.Present())
            data["ignoreCase"] = fopo.ignoreCase.Value();
    }
}