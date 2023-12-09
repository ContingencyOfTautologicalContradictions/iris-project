#include "DocumentSymbolOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentSymbolOptions& dso)
    {
        dso.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        dso.label = Json::Field<std::string>(data, "label");
    }

    void to_json(nlohmann::json& data, const DocumentSymbolOptions& dso)
    {
        if(dso.workDoneProgress.Present())
            data["workDoneProgress"] = dso.workDoneProgress.Value();
        if(dso.label.Present())
            data["label"] = dso.label.Value();
    }
}