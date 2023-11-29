#pragma once
#include "URI.hpp"
#include "../Field.hpp"
#include "ChangeAnnotationIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CreateFileOptions final
    {
    public:
        Json::Field<bool> overwrite, ignoreIfExists;
    };

    class [[nodiscard]] CreateFile final
    {
    public:
        std::string kind;

        DocumentUri uri;

        Json::Field<CreateFileOptions> options;

        Json::Field<ChangeAnnotationIdentifier> annotationId;
    };

    void from_json(const nlohmann::json&, CreateFileOptions&);

    void to_json(nlohmann::json&, const CreateFileOptions&);

    void from_json(const nlohmann::json&, CreateFile&);

    void to_json(nlohmann::json&, const CreateFile&);
}