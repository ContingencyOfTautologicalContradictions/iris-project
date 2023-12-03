#include "ClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ClientCapabilities& cc)
    {
        cc.workspace = Json::Field<Workspace>(data, "workspace");
        cc.textDocument = Json::Field<TextDocumentClientCapabilities>(data,
        "textDocument");
        cc.notebookDocument = Json::Field<NotebookDocumentClientCapabilities>(
        data, "notebookDocument");
        cc.window = Json::Field<Window>(data, "window");
        cc.general = Json::Field<General>(data, "general");
        if(data.contains("experimental"))
        {
            cc.experimental.Set();
            const nlohmann::json& experimental = data.at("experimental");
            if(experimental.is_boolean())
                cc.experimental.Value() = experimental.get<bool>();
            else if(experimental.is_number_integer())
                cc.experimental.Value() = experimental.get<std::int64_t>();
            else if(experimental.is_string())
                cc.experimental.Value() = experimental.get<std::string>();
        }
    }

    void to_json(nlohmann::json& data, const ClientCapabilities& cc)
    {
        if(cc.workspace.Present())
            data["workspace"] = cc.workspace.Value();
        if(cc.textDocument.Present())
            data["textDocument"] = cc.textDocument.Value();
        if(cc.notebookDocument.Present())
            data["notebookDocument"] = cc.notebookDocument.Value();
        if(cc.window.Present())
            data["window"] = cc.window.Value();
        if(cc.general.Present())
            data["general"] = cc.general.Value();
        if(cc.experimental.Present())
            std::visit([&](auto&& active)
            {
                data["experimental"] = active;
            }, cc.experimental.Value());
    }
}