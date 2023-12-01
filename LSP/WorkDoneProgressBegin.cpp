#include "WorkDoneProgressBegin.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, WorkDoneProgressBegin& wdpb)
    {
        wdpb.kind = data.at("kind").get<std::string>();
        wdpb.title = data.at("title").get<std::string>();
        wdpb.cancellable = Json::Field<bool>(data, "cancellable");
        wdpb.message = Json::Field<std::string>(data, "message");
        wdpb.percentage = Json::Field<std::uint8_t>(data, "percentage");
    }

    void to_json(nlohmann::json& data, const WorkDoneProgressBegin& wdpb)
    {
        data["kind"] = wdpb.kind;
        data["title"] = wdpb.title;
        if(wdpb.cancellable.Present())
            data["cancellable"] = wdpb.cancellable.Value();
        if(wdpb.message.Present())
            data["message"] = wdpb.message.Value();
        if(wdpb.percentage.Present())
            data["percentage"] = wdpb.percentage.Value();
    }
}