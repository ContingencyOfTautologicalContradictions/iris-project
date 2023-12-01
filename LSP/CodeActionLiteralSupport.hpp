#pragma once
#include "CodeActionKind.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CodeActionLiteralSupport final
    {
    public:
        CodeActionKind codeActionKind;
    };

    void from_json(const nlohmann::json&, CodeActionLiteralSupport&);

    void to_json(nlohmann::json&, const CodeActionLiteralSupport&);
}