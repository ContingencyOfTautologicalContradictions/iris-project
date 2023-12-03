#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DidChangeConfigurationClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;
    };

    void from_json(const nlohmann::json&,
    DidChangeConfigurationClientCapabilities&);
    
    void to_json(nlohmann::json&, const
    DidChangeConfigurationClientCapabilities&);
}