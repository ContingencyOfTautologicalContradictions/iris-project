#include "NotebookSelector.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, NotebookSelector& ns)
    {
        if(data.contains("notebook"))
        {
            ns.notebook.Set();
            const nlohmann::json& notebook = data.at("notebook");
            if(notebook.is_string())
                ns.notebook.Value() = notebook.get<std::string>();
            else
                ns.notebook.Value() = notebook.get<NotebookDocumentFilter>();
        }
        ns.cells = Json::Field<std::vector<Cells>>(data, "cells");
    }

    void to_json(nlohmann::json& data, const NotebookSelector& ns)
    {
        if(ns.notebook.Present())
            std::visit([&](auto&& active)
            {
                data["notebook"] = active;
            }, ns.notebook.Value());
        if(ns.cells.Present())
            data["cells"] = ns.cells.Value();
    }
}