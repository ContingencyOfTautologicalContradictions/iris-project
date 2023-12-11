#include "Workspace2.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Workspace2& w)
    {
        w.workspaceFolders = Json::Field<WorkspaceFoldersServerCapabilities>(
        data, "workspaceFolders");
        w.fileOperations = Json::Field<FileOperations2>(data, "fileOperations")
        ;
    }

    void to_json(nlohmann::json& data, const Workspace2& w)
    {
        if(w.workspaceFolders.Present())
            data["workspaceFolders"] = w.workspaceFolders.Value();
        if(w.fileOperations.Present())
            data["fileOperations"] = w.fileOperations.Value();
    }
}