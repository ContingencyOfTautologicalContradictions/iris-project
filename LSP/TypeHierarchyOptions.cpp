#include "TypeHierarchyOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TypeHierarchyOptions& tho)
    {
        tho.workDoneProgress = Json::Field<bool>(data, "workDoneProgress");
    }

    void to_json(nlohmann::json& data, const TypeHierarchyOptions& tho)
    {
        if(tho.workDoneProgress.Present())
            data["workDOneProgress"] = tho.workDoneProgress.Value();
    }
}