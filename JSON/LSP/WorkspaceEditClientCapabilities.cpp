#include "WorkspaceEditClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ChangeAnnotationSupport& cas)
    {
        cas.groupsOnLabel = Json::Field<bool>(data, "groupsOnLabel");
    }

    void to_json(nlohmann::json& data, const ChangeAnnotationSupport& cas)
    {
        if(cas.groupsOnLabel.Present())
            data["groupsOnLabel"] = cas.groupsOnLabel.Value();
    }

    void from_json(const nlohmann::json& data, WorkspaceEditClientCapabilities&
    wecc)
    {
        wecc.documentChanges = Json::Field<bool>(data, "documentChanges");
        wecc.resourceOperations = Json::Field<std::vector<ResourceOperationKind
        >>(data, "resourceOperations");
        wecc.failureHandling = Json::Field<FailureHandlingKind>(data,
        "failureHandling");
        wecc.normalizesLineEndings = Json::Field<bool>(data,
        "normalizesLineEndings");
        wecc.changeAnnotationSupport = Json::Field<ChangeAnnotationSupport>(
        data, "changeAnnotationSupport");
    }

    void to_json(nlohmann::json& data, const WorkspaceEditClientCapabilities&
    wecc)
    {
        if(wecc.documentChanges.Present())
            data["documentChanges"] = wecc.documentChanges.Value();
        if(wecc.resourceOperations.Present())
            data["resourceOperations"] = wecc.resourceOperations.Value();
        if(wecc.failureHandling.Present())
            data["failureHandling"] = wecc.failureHandling.Value();
        if(wecc.normalizesLineEndings.Present())
            data["normalizesLineEndings"] = wecc.normalizesLineEndings.Value();
        if(wecc.changeAnnotationSupport.Present())
            data["changeAnnotationSupport"] = wecc.changeAnnotationSupport.
            Value();
    }
}