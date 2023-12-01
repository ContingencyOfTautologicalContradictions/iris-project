#pragma once
#include "../JSON/Field.hpp"


namespace Iris::LSP
{
    class [[nodiscard]] WorkDoneProgressBegin final
    {
    public:
        std::string kind, title;

        Json::Field<bool> cancellable;

        Json::Field<std::string> message;

        Json::Field<std::uint8_t> percentage;
    };

    void from_json(const nlohmann::json&, WorkDoneProgressBegin&);

    void to_json(nlohmann::json&, const WorkDoneProgressBegin&);
}