#include "Window.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Window& w)
    {
        w.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        w.showMessage = Json::Field<ShowMessageRequestClientCapabilities>(data,
        "showMessage");
        w.showDocument = Json::Field<ShowDocumentClientCapabilities>(data,
        "showDocument");
    }

    void to_json(nlohmann::json& data, const Window& w)
    {
        if(w.workDoneProgress.Present())
            data["workDoneProgress"] = w.workDoneProgress.Value();
        if(w.showMessage.Present())
            data["showMessage"] = w.showMessage.Value();
        if(w.showDocument.Present())
            data["showDocument"] = w.showDocument.Value();
    }
}