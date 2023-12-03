#include "NotebookDocumentSyncClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    NotebookDocumentSyncClientCapabilities& ndscc)
    {
        ndscc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        ndscc.executionSummarySupport = Json::Field<bool>(data,
        "executionSummarySupport");
    }

    void to_json(nlohmann::json& data, const
    NotebookDocumentSyncClientCapabilities& ndscc)
    {
        if(ndscc.dynamicRegistration.Present())
            data["dynamicRegistration"] = ndscc.dynamicRegistration.Value();
        if(ndscc.executionSummarySupport.Present())
            data["executionSummarySupport"] = ndscc.executionSummarySupport.
            Value();
    }
}