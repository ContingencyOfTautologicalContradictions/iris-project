#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkDoneProgressReport final
    {
    public:
        std::string kind;

        Json::Field<bool> cancellable;

        Json::Field<std::string> message;

        Json::Field<std::uint8_t> percentage;
    };

    void from_json(const nlohmann::json&, WorkDoneProgressReport&);

    void to_json(nlohmann::json&, const WorkDoneProgressReport&);
}