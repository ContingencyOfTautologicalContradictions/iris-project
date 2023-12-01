#pragma once
#include "../JSON/Field.hpp"
#include "PrepareSupportDefaultBehavior.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] RenameClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, prepareSupport;

        Json::Field<PrepareSupportDefaultBehavior>
        prepareSupportDefaultBehavior;

        Json::Field<bool> honorsChangeAnnotations;
    };

    void from_json(const nlohmann::json&, RenameClientCapabilities&);

    void to_json(nlohmann::json&, const RenameClientCapabilities&);
}