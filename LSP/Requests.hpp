#pragma once
#include "Empty.hpp"
#include "Delta.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Requests final
    {
    public:
        Json::Field<std::variant<bool, Empty>> range;

        Json::Field<std::variant<bool, Delta>> full;
    };

    void from_json(const nlohmann::json&, Requests&);

    void to_json(nlohmann::json&, const Requests&);
}