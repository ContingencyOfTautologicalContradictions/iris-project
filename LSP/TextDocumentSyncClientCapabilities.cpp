#include "TextDocumentSyncClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data,
    TextDocumentSyncClientCapabilities& tdscc)
    {
        tdscc.dynamicRegistration = Json::Field<bool>(data,
        "dynamicRegistration");
        tdscc.willSave = Json::Field<bool>(data, "willSave");
        tdscc.willSaveWaitUntil = Json::Field<bool>(data, "willSaveWaitUntil");
        tdscc.didSave = Json::Field<bool>(data, "didSave");
    }

    void to_json(nlohmann::json& data, const TextDocumentSyncClientCapabilities
    & tdscc)
    {
        if(tdscc.dynamicRegistration.Present())
            data["dynamicRegistration"] = tdscc.dynamicRegistration.Value();
        if(tdscc.willSave.Present())
            data["willSave"] = tdscc.willSave.Value();
        if(tdscc.willSaveWaitUntil.Present())
            data["willSaveWaitUntil"] = tdscc.willSaveWaitUntil.Value();
        if(tdscc.didSave.Present())
            data["didSave"] = tdscc.didSave.Value();
    }
}