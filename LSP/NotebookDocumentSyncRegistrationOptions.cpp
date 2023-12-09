#include "NotebookDocumentSyncRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    NotebookDocumentSyncRegistrationOptions& ndsro)
    {
        ndsro.notebookSelector = data.at("notebookSelector").get<std::vector<
        NotebookSelector>>();
        ndsro.save = Json::Field<bool>(data, "save");
        ndsro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const
    NotebookDocumentSyncRegistrationOptions& ndsro)
    {
        data["notebookSelector"] = ndsro.notebookSelector;
        if(ndsro.save.Present())
            data["save"] = ndsro.save.Value();
        if(ndsro.id.Present())
            data["id"] = ndsro.id.Value();
    }
}