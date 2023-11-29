#include "WorkspaceFolder.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, WorkspaceFolder& wf)
    {
        wf.uri = data.at("uri").get<URI>();
        wf.name = data.at("name").get<std::string>();
    }

    void to_json(nlohmann::json& data, const WorkspaceFolder& wf)
    {
        data["uri"] = wf.uri;
        data["name"] = wf.name;
    }
}