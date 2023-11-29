#pragma once
#include "URI.hpp"
#include "../Field.hpp"
#include "ChangeAnnotationIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] RenameFileOptions final
    {
    public:
        Json::Field<bool> overwrite, ignoreIfExists;
    };

    class [[nodiscard]] RenameFile final
    {
    public:
        std::string kind;

        DocumentUri oldUri, newUri;

        Json::Field<RenameFileOptions> options;

        Json::Field<ChangeAnnotationIdentifier> annotationId;
    };

    void from_json(const nlohmann::json&, RenameFileOptions&);

    void to_json(nlohmann::json&, const RenameFileOptions&);

    void from_json(const nlohmann::json&, RenameFile&);

    void to_json(nlohmann::json&, const RenameFile&);
}