#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ParameterInformation final
    {
    public:
        Json::Field<bool> labelOffsetSupport;
    };

    void from_json(const nlohmann::json&, ParameterInformation&);

    void to_json(nlohmann::json&, const ParameterInformation&);
}