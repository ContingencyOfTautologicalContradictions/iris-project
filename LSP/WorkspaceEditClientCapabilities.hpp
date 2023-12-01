#pragma once
#include "FailureHandlingKind.hpp"
#include "ResourceOperationKind.hpp"
#include "ChangeAnnotationSupport.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkspaceEditClientCapabilities final
    {
    public:
        Json::Field<bool> documentChanges;

        Json::Field<std::vector<ResourceOperationKind>> resourceOperations;

        Json::Field<FailureHandlingKind> failureHandling;

        Json::Field<bool> normalizesLineEndings;

        Json::Field<ChangeAnnotationSupport> changeAnnotationSupport;
    };

    void from_json(const nlohmann::json&, WorkspaceEditClientCapabilities&);

    void to_json(nlohmann::json&, const WorkspaceEditClientCapabilities&);
}