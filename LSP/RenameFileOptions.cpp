#include "RenameFileOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, RenameFileOptions& rfo)
    {
        rfo.overwrite = Json::Field<bool>(data, "overwrite");
        rfo.ignoreIfExists = Json::Field<bool>(data, "ignoreIfExists");
    }

    void to_json(nlohmann::json& data, const RenameFileOptions& rfo)
    {
        if(rfo.overwrite.Present())
            data["overwrite"] = rfo.overwrite.Value();
        if(rfo.ignoreIfExists.Present())
            data["ignoreIfExists"] = rfo.ignoreIfExists.Value();
    }
}