#include "Progress.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Progress& p)
    {
        p.kind = data.at("kind").get<std::string>();
        p.title = data.at("title").get<std::string>();
        p.cancellable = Json::Field<bool>(data, "cancellable");
        p.message = Json::Field<std::string>(data, "message");
        p.percentage = Json::Field<std::uint8_t>(data, "percentage");
    }

    void to_json(nlohmann::json& data, const Progress& p)
    {
        data["kind"] = p.kind;
        data["title"] = p.title;
        if(p.cancellable.Present())
            data["cancellable"] = p.cancellable.Value();
        if(p.message.Present())
            data["message"] = p.message.Value();
        if(p.percentage.Present())
            data["percentage"] = p.percentage.Value();
    }
}