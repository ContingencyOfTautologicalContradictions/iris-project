#include "RegularExpressionsClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    RegularExpressionsClientCapabilities& recc)
    {
        recc.engine = data.at("engine").get<std::string>();
        recc.version = Json::Field<std::string>(data, "version");
    }

    void to_json(nlohmann::json& data, const
    RegularExpressionsClientCapabilities& recc)
    {
        data["engine"] = recc.engine;
        if(recc.version.Present())
            data["version"] = recc.version.Value();
    }
}