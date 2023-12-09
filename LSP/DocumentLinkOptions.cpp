#include "DocumentLinkOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, DocumentLinkOptions& dlo)
    {
        dlo.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        dlo.resolveProvider = Json::Field<bool>(data, "resolveProvider");
    }

    void to_json(nlohmann::json& data, const DocumentLinkOptions& dlo)
    {
        if(dlo.workDoneProgress.Present())
            data["workDoneProgress"] = dlo.workDoneProgress.Value();
        if(dlo.resolveProvider.Present())
            data["resolveProvider"] = dlo.resolveProvider.Value();
    }
}