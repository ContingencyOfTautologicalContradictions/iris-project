#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] ChangeAnnotation final
    {
    public:
        std::string label;

        Json::Field<bool> needsConfirmation;

        Json::Field<std::string> description;
    };

    void from_json(const nlohmann::json&, ChangeAnnotation&);

    void to_json(nlohmann::json&, const ChangeAnnotation&);
}