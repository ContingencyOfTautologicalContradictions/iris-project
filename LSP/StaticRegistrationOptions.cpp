#include "StaticRegistrationOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, StaticRegistrationOptions& sro)
    {
        sro.id = Json::Field<std::string>(data, "id");
    }

    void to_json(nlohmann::json& data, const StaticRegistrationOptions& sro)
    {
        if(sro.id.Present())
            data["id"] = sro.id.Value();
    }
}