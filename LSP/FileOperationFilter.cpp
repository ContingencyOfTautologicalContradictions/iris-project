#include "FileOperationFilter.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FileOperationFilter& fof)
    {
        fof.scheme = Json::Field<std::string>(data, "scheme");
        fof.pattern = data.at("pattern").get<FileOperationPattern>();
    }

    void to_json(nlohmann::json& data, const FileOperationFilter& fof)
    {
        if(fof.scheme.Present())
            data["scheme"] = fof.scheme.Value();
        data["pattern"] = fof.pattern;
    }
}