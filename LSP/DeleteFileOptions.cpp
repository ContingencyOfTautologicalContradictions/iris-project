#include "DeleteFileOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DeleteFileOptions& dfo)
    {
        dfo.recursive = Json::Field<bool>(data, "recursive");
        dfo.ignoreIfExists = Json::Field<bool>(data, "ignoreIfExists");
    }

    void to_json(nlohmann::json& data, const DeleteFileOptions& dfo)
    {
        if(dfo.recursive.Present())
            data["recursive"] = dfo.recursive.Value();
        if(dfo.ignoreIfExists.Present())
            data["ignoreIfExists"] = dfo.ignoreIfExists.Value();
    }
}