#include "WorkDoneProgressReport.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, WorkDoneProgressReport& wdpr)
    {
        wdpr.kind = data.at("kind").get<std::string>();
        wdpr.cancellable = Json::Field<bool>(data, "cancellable");
        wdpr.message = Json::Field<std::string>(data, "message");
        wdpr.percentage = Json::Field<std::uint8_t>(data, "percentage");
    }

    void to_json(nlohmann::json& data, const WorkDoneProgressReport& wdpr)
    {
        data["kind"] = wdpr.kind;
        if(wdpr.cancellable.Present())
            data["cancellable"] = wdpr.cancellable.Value();
        if(wdpr.message.Present())
            data["message"] = wdpr.message.Value();
        if(wdpr.percentage.Present())
            data["percentage"] = wdpr.percentage.Value();
    }
}