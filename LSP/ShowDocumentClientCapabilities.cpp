#include "ShowDocumentClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, ShowDocumentClientCapabilities&
    sdcc)
    {
        sdcc.support = data.at("support").get<bool>();
    }

    void to_json(nlohmann::json& data, const ShowDocumentClientCapabilities&
    sdcc)
    {
        data["support"] = sdcc.support;
    }
}