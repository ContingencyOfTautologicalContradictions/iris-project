#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkDoneProgressEnd final
    {
    public:
        std::string kind;

        Json::Field<std::string> message;
    };

    void from_json(const nlohmann::json&, WorkDoneProgressEnd&);

    void to_json(nlohmann::json&, const WorkDoneProgressEnd&);
}