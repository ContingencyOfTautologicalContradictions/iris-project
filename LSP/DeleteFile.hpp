#pragma once
#include "URI.hpp"
#include "DeleteFileOptions.hpp"
#include "ChangeAnnotationIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DeleteFile final
    {
    public:
        std::string kind;

        DocumentUri uri;

        Json::Field<DeleteFileOptions> options;

        Json::Field<ChangeAnnotationIdentifier> annotationId;
    };

    void from_json(const nlohmann::json&, DeleteFile&);

    void to_json(nlohmann::json&, const DeleteFile&);
}