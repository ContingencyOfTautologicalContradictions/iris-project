#include "FileOperationPattern.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FileOperationPattern& fop)
    {
        fop.glob = data.at("glob").get<std::string>();
        fop.matches = Json::Field<FileOperationPatternKind>(data, "matches");
        fop.options = Json::Field<FileOperationPatternOptions>(data, "options")
        ;
    }

    void to_json(nlohmann::json& data, const FileOperationPattern& fop)
    {
        data["glob"] = fop.glob;
        if(fop.matches.Present())
            data["matches"] = fop.matches.Value();
        if(fop.options.Present())
            data["options"] = fop.options.Value();
    }
}