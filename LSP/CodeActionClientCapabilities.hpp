#pragma once
#include "../JSON/Field.hpp"
#include "ResolveSupport.hpp"
#include "CodeActionLiteralSupport.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CodeActionClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Json::Field<CodeActionLiteralSupport> codeActionLiteralSupport;

        Json::Field<bool> isPreferredSupport, disabledSupport, dataSupport;

        Json::Field<ResolveSupport> resolveSupport;

        Json::Field<bool> honorsChangeAnnotations;
    };

    void from_json(const nlohmann::json&, CodeActionClientCapabilities&);

    void to_json(nlohmann::json&, const CodeActionClientCapabilities&);
}