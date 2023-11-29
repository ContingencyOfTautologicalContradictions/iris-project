#include "WorkDoneProgressEnd.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, WorkDoneProgressEnd& wdpe)
    {
        wdpe.kind = data.at("kind").get<std::string>();
        wdpe.message = Json::Field<std::string>(data, "message");
    }

    void to_json(nlohmann::json& data, const WorkDoneProgressEnd& wdpe)
    {
        data["kind"] = wdpe.kind;
        if(wdpe.message.Present())
            data["message"] = wdpe.message.Value();
    }
}