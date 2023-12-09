#include "NotebookDocumentSyncOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, NotebookDocumentSyncOptions&
    ndso)
    {
        ndso.notebookSelector = data.at("notebookSelector").get<std::vector<
        NotebookSelector>>();
        ndso.save = Json::Field<bool>(data, "save");
    }

    void to_json(nlohmann::json& data, const NotebookDocumentSyncOptions& ndso)
    {
        data["notebookSelector"] = ndso.notebookSelector;
        if(ndso.save.Present())
            data["save"] = ndso.save.Value();
    }
}