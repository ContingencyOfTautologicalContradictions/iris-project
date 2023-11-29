#pragma once
#include "Range.hpp"
#include "ChangeAnnotationIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] AnnotatedTextEdit final
    {
    public:
        Range range;

        std::string newText;

        ChangeAnnotationIdentifier annotationId;
    };

    void from_json(const nlohmann::json&, AnnotatedTextEdit&);

    void to_json(nlohmann::json&, const AnnotatedTextEdit&);
}