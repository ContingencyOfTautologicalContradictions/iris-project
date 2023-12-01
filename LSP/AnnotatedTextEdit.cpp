#include "AnnotatedTextEdit.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, AnnotatedTextEdit& ate)
    {
        ate.range = data.at("range").get<Range>();
        ate.newText = data.at("newText").get<std::string>();
        ate.annotationId = data.at("annotationId").get<
        ChangeAnnotationIdentifier>();
    }

    void to_json(nlohmann::json& data, const AnnotatedTextEdit& ate)
    {
        data["range"] = ate.range;
        data["newText"] = ate.newText;
        data["annotationId"] = ate.annotationId;
    }
}