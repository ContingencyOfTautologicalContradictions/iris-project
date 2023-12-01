#pragma once
#include "URI.hpp"
#include "../JSON/Field.hpp"
#include "ChangeAnnotationIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DeleteFileOptions final
    {
    public:
        Json::Field<bool> recursive, ignoreIfNotExists;
    };

    class [[nodiscard]] DeleteFile final
    {
    public:
        std::string kind;

        DocumentUri uri;

        Json::Field<DeleteFileOptions> options;

        Json::Field<ChangeAnnotationIdentifier> annotationId;
    };

    void from_json(const nlohmann::json&, DeleteFileOptions&);

    void to_json(nlohmann::json&, const DeleteFileOptions&);

    void from_json(const nlohmann::json&, DeleteFile&);

    void to_json(nlohmann::json&, const DeleteFile&);
}