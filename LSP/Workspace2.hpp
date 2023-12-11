#pragma once
#include "FileOperations2.hpp"
#include "WorkspaceFoldersServerCapabilities.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Workspace2 final
    {
    public:
        Json::Field<WorkspaceFoldersServerCapabilities> workspaceFolders;

        Json::Field<FileOperations2> fileOperations;
    };

    void from_json(const nlohmann::json&, Workspace2&);

    void to_json(nlohmann::json&, const Workspace2&);
}