#pragma once
#include "Progress.hpp"
#include "ProgressToken.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ProgressParams final
    {
    public:
        ProgressToken token;

        Progress value;
    };

    void from_json(const nlohmann::json&, ProgressParams&);

    void to_json(nlohmann::json&, const ProgressParams&);
}