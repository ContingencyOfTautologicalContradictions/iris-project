#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] StaticRegistrationOptions final
    {
    public:
        Json::Field<std::string> id;
    };

    void from_json(const nlohmann::json&, StaticRegistrationOptions&);

    void to_json(nlohmann::json&, const StaticRegistrationOptions&);
}