#pragma once
#include "URI.hpp"
#include "RenameFileOptions.hpp"
#include "ChangeAnnotationIdentifier.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] RenameFile final
    {
    public:
        std::string kind;

        DocumentUri oldUri, newUri;

        Json::Field<RenameFileOptions> options;

        Json::Field<ChangeAnnotationIdentifier> annotationId;
    };

    void from_json(const nlohmann::json&, RenameFile&);

    void to_json(nlohmann::json&, const RenameFile&);
}