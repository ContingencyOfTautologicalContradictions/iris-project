#include "RegularExpressionsClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    RegularExpressionsClientCapabilities& recc)
    {
        recc.engine = data.at("engine").get<std::string>();
        recc.version = Json::Field<std::string>(data, "version");
    }
}