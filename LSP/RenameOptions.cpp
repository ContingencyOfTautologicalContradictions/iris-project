#include "RenameOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, RenameOptions& ro)
    {
        ro.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
        ro.prepareProvider = Json::Field<bool>(data, "prepareProvider");
    }

    void to_json(nlohmann::json& data, const RenameOptions& ro)
    {
        if(ro.workDoneProgress.Present())
            data["workDoneProgress"] = ro.workDoneProgress.Value();
        if(ro.prepareProvider.Present())
            data["prepareProvider"] = ro.prepareProvider.Value();
    }
}