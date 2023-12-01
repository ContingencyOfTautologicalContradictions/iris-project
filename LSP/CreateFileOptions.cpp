#include "CreateFileOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CreateFileOptions& cfo)
    {
        cfo.overwrite = Json::Field<bool>(data, "overwrite");
        cfo.ignoreIfExists = Json::Field<bool>(data, "ignoreIfExists");
    }

    void to_json(nlohmann::json& data, const CreateFileOptions& cfo)
    {
        if(cfo.overwrite.Present())
            data["overwrite"] = cfo.overwrite.Value();
        if(cfo.ignoreIfExists.Present())
            data["ignoreIfExists"] = cfo.ignoreIfExists.Value();
    }
}