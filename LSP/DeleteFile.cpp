#include "DeleteFile.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DeleteFile& df)
    {
        df.kind = data.at("kind").get<std::string>();
        df.uri = data.at("uri").get<DocumentUri>();
        df.options = Json::Field<DeleteFileOptions>(data, "options");
        df.annotationId = Json::Field<ChangeAnnotationIdentifier>(data,
        "annotationId");
    }

    void to_json(nlohmann::json& data, const DeleteFile& df)
    {
        data["kind"] = df.kind;
        data["uri"] = df.uri;
        if(df.options.Present())
            data["options"] = df.options.Value();
        if(df.annotationId.Present())
            data["annotationId"] = df.annotationId.Value();
    }
}