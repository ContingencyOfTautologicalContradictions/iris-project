#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    using ResourceOperationKind = std::string;

    using FailureHandlingKind = std::string;

    class [[nodiscard]] ChangeAnnotationSupport final
    {
    public:
        Json::Field<bool> groupsOnLabel;
    };

    class [[nodiscard]] WorkspaceEditClientCapabilities final
    {
    public:
        Json::Field<bool> documentChanges;

        Json::Field<std::vector<ResourceOperationKind>> resourceOperations;

        Json::Field<FailureHandlingKind> failureHandling;

        Json::Field<bool> normalizesLineEndings;

        Json::Field<ChangeAnnotationSupport> changeAnnotationSupport;
    };

    void from_json(const nlohmann::json&, ChangeAnnotationSupport&);

    void to_json(nlohmann::json&, const ChangeAnnotationSupport&);

    void from_json(const nlohmann::json&, WorkspaceEditClientCapabilities&);

    void to_json(nlohmann::json&, const WorkspaceEditClientCapabilities&);
}