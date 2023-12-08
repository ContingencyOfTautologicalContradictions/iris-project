#include "TextDocumentSyncOptions.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, TextDocumentSyncOptions& tdso)
    {
        tdso.openClose = Json::Field<bool>(data, "openClose");
        tdso.change = Json::Field<TextDocumentSyncKind>(data, "change");
    }

    void to_json(nlohmann::json& data, const TextDocumentSyncOptions& tdso)
    {
        if(tdso.openClose.Present())
            data["openClose"] = tdso.openClose.Value();
        if(tdso.change.Present())
            data["change"] = tdso.change.Value();
    }
}