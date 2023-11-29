#include "RenameFile.hpp"

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

    void from_json(const nlohmann::json& data, RenameFile& rf)
    {
        rf.kind = data.at("kind").get<std::string>();
        rf.oldUri = data.at("oldUri").get<DocumentUri>();
        rf.newUri = data.at("newUri").get<DocumentUri>();
        rf.options = Json::Field<RenameFileOptions>(data, "options");
        rf.annotationId = Json::Field<ChangeAnnotationIdentifier>(data,
        "annotationId");
    }

    void to_json(nlohmann::json& data, const RenameFile& rf)
    {
        data["kind"] = rf.kind;
        data["oldUri"] = rf.oldUri;
        data["newUri"] = rf.newUri;
        if(rf.options.Present())
            data["options"] = rf.options.Value();
        if(rf.annotationId.Present())
            data["annotationId"] = rf.annotationId.Value();
    }
}