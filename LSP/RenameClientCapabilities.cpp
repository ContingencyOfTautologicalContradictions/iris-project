#include "RenameClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, RenameClientCapabilities& rcc)
    {
        rcc.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration"
        );
        rcc.prepareSupport = Json::Field<bool>(data, "prepareSupport");
        rcc.prepareSupportDefaultBehavior = Json::Field<
        PrepareSupportDefaultBehavior>(data, "prepareSupportDefaultBehavior");
        rcc.honorsChangeAnnotations = Json::Field<bool>(data,
        "honorsChangeAnnotations");
    }

    void to_json(nlohmann::json& data, const RenameClientCapabilities& rcc)
    {
        if(rcc.dynamicRegistration.Present())
            data["dynamicRegistration"] = rcc.dynamicRegistration.Value();
        if(rcc.prepareSupport.Present())
            data["prepareSupport"] = rcc.prepareSupport.Value();
        if(rcc.prepareSupportDefaultBehavior.Present())
            data["prepareSupportDefaultBehavior"] = rcc.
            prepareSupportDefaultBehavior.Value();
        if(rcc.honorsChangeAnnotations.Present())
            data["honorsChangeAnnotations"] = rcc.honorsChangeAnnotations.Value
            ();
    }
}