#pragma once
#include "../JSON/Json.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] StaleRequestSupport final
    {
    public:
        bool cancel;

        std::vector<std::string> retryOnContentModified;
    };

    void from_json(const nlohmann::json&, StaleRequestSupport&);

    void to_json(nlohmann::json&, const StaleRequestSupport&);
}