#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ExecuteCommandOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        std::vector<std::string> commands;
    };

    void from_json(const nlohmann::json&, ExecuteCommandOptions&);

    void to_json(nlohmann::json&, const ExecuteCommandOptions&);
}