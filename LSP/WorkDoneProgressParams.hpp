#pragma once
#include "ProgressParams.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkDoneProgressParams final
    {
    public:
        Json::Field<ProgressToken> workDoneToken;
    };

    void from_json(const nlohmann::json&, WorkDoneProgressParams&);

    void to_json(nlohmann::json&, const WorkDoneProgressParams&);
}