#include "WorkspaceFoldersServerCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    WorkspaceFoldersServerCapabilities& wfsc)
    {
        wfsc.supported = Json::Field<bool>(data, "supported");
        if(data.contains("changeNotifications"))
        {
            wfsc.changeNotifications.Set();
            const nlohmann::json& changeNotifications = data.at(
            "changeNotifications");
            if(changeNotifications.is_boolean())
                wfsc.changeNotifications.Value() = changeNotifications.get<bool
                >();
            else
                wfsc.changeNotifications.Value() = changeNotifications.get<std
                ::string>();
        }
    }

    void to_json(nlohmann::json& data, const WorkspaceFoldersServerCapabilities
    & wfsc)
    {
        if(wfsc.supported.Present())
            data["supported"] = wfsc.supported.Value();
        if(wfsc.changeNotifications.Present())
            std::visit([&](auto&& active)
            {
                data["changeNotifications"] = active;
            }, wfsc.changeNotifications.Value());
    }
}