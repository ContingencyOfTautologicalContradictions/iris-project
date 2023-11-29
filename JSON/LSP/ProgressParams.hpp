#pragma once
#include "../Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Progress final
    {
    public:
        std::string kind/* begin, report or end */, title;

        Json::Field<bool> cancellable;

        Json::Field<std::string> message;

        Json::Field<std::uint8_t> percentage;
    };

    class [[nodiscard]] ProgressParams final
    {
    public:
        std::variant<std::int64_t, std::string> token;

        Progress value;
    };

    void from_json(const nlohmann::json&, Progress&);

    void to_json(nlohmann::json&, const Progress&);

    void from_json(const nlohmann::json&, ProgressParams&);

    void to_json(nlohmann::json&, const ProgressParams&);
}