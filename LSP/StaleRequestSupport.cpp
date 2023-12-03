#include "StaleRequestSupport.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, StaleRequestSupport& srs)
    {
        srs.cancel = data.at("cancel").get<bool>();
        srs.retryOnContentModified = data.at("retryOnContentModified").get<std
        ::vector<std::string>>();
    }

    void to_json(nlohmann::json& data, const StaleRequestSupport& srs)
    {
        data["cancel"] = srs.cancel;
        data["retryOnContentModified"] = srs.retryOnContentModified;
    }
}