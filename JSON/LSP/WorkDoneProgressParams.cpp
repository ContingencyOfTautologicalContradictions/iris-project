#include "WorkDoneProgressParams.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, WorkDoneProgressParams& wdpp)
    {
        if(data.contains("workDoneToken"))
        {
            wdpp.workDoneToken.Set();
            const nlohmann::json& workDoneToken = data.at("workDoneToken");
            if(workDoneToken.is_string())
                wdpp.workDoneToken.Value() = workDoneToken.get<std::string>();
            else
                wdpp.workDoneToken.Value() = workDoneToken.get<std::int64_t>();
        }
    }

    void to_json(nlohmann::json& data, const WorkDoneProgressParams& wdpp)
    {
        if(wdpp.workDoneToken.Present())
            std::visit([&](auto&& active)
            {
                data["workDoneToken"] = active;
            }, wdpp.workDoneToken.Value());
    }
}