#include "NotebookDocumentClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    NotebookDocumentClientCapabilities& ndcc)
    {
        ndcc.synchronization = data.at("synchronization").get<
        NotebookDocumentSyncClientCapabilities>();
    }

    void to_json(nlohmann::json& data, const NotebookDocumentClientCapabilities
    & ndcc)
    {
        data["synchronization"] = ndcc.synchronization;
    }
}