#include "CancelParams.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CancelParams& cp)
    {
        const nlohmann::json& id = data.at("id");
        if(id.is_string())
            cp.id = id.get<std::string>();
        else
            cp.id = id.get<std::int64_t>();
    }
}