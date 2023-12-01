#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ChangeAnnotationSupport final
    {
    public:
        Json::Field<bool> groupsOnLabel;
    };

    void from_json(const nlohmann::json&, ChangeAnnotationSupport&);

    void to_json(nlohmann::json&, const ChangeAnnotationSupport&);
}