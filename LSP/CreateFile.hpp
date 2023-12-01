#pragma once
#include "URI.hpp"
#include "CreateFileOptions.hpp"
#include "ChangeAnnotationIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CreateFile final
    {
    public:
        std::string kind;

        DocumentUri uri;

        Json::Field<CreateFileOptions> options;

        Json::Field<ChangeAnnotationIdentifier> annotationId;
    };

    void from_json(const nlohmann::json&, CreateFile&);

    void to_json(nlohmann::json&, const CreateFile&);
}