#include "FileOperationRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, FileOperationRegistrationOptions
    & foro)
    {
        foro.filters = data.at("filters").get<std::vector<FileOperationFilter>>
        ();
    }

    void to_json(nlohmann::json& data, const FileOperationRegistrationOptions&
    foro)
    {
        data["filters"] = foro.filters;
    }
}