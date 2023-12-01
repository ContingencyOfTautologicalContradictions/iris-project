#include "PartialResultParams.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, PartialResultParams& prp)
    {
        if(data.contains("partialResultToken"))
        {
            prp.partialResultToken.Set();
            const nlohmann::json& partialResultToken = data.at(
            "partialResultToken");
            if(partialResultToken.is_string())
                prp.partialResultToken.Value() = partialResultToken.get<std::
                string>();
            else
                prp.partialResultToken.Value() = partialResultToken.get<std::
                int64_t>();
        }
    }

    void to_json(nlohmann::json& data, const PartialResultParams& prp)
    {
        if(prp.partialResultToken.Present())
            std::visit([&](auto&& active)
            {
                data["partialResultToken"] = active;
            }, prp.partialResultToken.Value());
    }
}