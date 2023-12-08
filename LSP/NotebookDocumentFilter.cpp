#include "NotebookDocumentFilter.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TextDocumentFilter& tdf)
    {
        tdf.notebookType = Json::Field<std::string>(data, "notebookType");
        tdf.scheme = Json::Field<std::string>(data, "scheme");
        tdf.pattern = Json::Field<std::string>(data, "pattern");
    }

    void to_json(nlohmann::json& data, const TextDocumentFilter& tdf)
    {
        if(tdf.notebookType.Present())
            data["notebookType"] = tdf.notebookType.Value();
        if(tdf.scheme.Present())
            data["scheme"] = tdf.scheme.Value();
        if(tdf.pattern.Present())
            data["pattern"] = tdf.pattern.Value();
    }
}