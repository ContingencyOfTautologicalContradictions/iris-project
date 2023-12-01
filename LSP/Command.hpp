#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Command final
    {
    public:
        std::string title, command;

        using Arguments = std::optional<std::variant<bool, std::int64_t, std::
        string>>;

        Json::Field<std::vector<Arguments>> arguments;
    };

    void from_json(const nlohmann::json&, Command&);

    void to_json(nlohmann::json&, const Command&);
}