#pragma once
#include "../Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] RegularExpressionsClientCapabilities final
    {
    public:
        std::string engine;

        Json::Field<std::string> version;
    };

    void from_json(const nlohmann::json&, RegularExpressionsClientCapabilities&
    );
}