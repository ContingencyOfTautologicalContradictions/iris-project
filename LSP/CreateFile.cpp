#include "CreateFile.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CreateFile& cf)
    {
        cf.kind = data.at("kind").get<std::string>();
        cf.uri = data.at("uri").get<DocumentUri>();
        cf.options = Json::Field<CreateFileOptions>(data, "options");
        cf.annotationId = Json::Field<ChangeAnnotationIdentifier>(data,
        "annotationId");
    }

    void to_json(nlohmann::json& data, const CreateFile& cf)
    {
        data["kind"] = cf.kind;
        data["uri"] = cf.uri;
        if(cf.options.Present())
            data["options"] = cf.options.Value();
        if(cf.annotationId.Present())
            data["annotationId"] = cf.annotationId.Value();
    }
}