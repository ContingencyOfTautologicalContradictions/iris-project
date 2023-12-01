#include "CodeDescription.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CodeDescription& cd)
    {
        cd.href = data.at("href").get<URI>();
    }

    void to_json(nlohmann::json& data, const CodeDescription& cd)
    {
        data["href"] = cd.href;
    }
}