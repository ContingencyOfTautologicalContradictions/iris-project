#include "CompletionClientCapabilities.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CompletionClientCapabilities&
    ccc)
    {
        ccc.dynamicRegistration = Json::Field<bool>(data, "dynamicRegistration"
        );
        ccc.completionItem = Json::Field<CompletionItem>(data, "completionItem"
        );
        ccc.completionItemKind = Json::Field<CompletionItemKind>(data,
        "completionItemKind");
        ccc.contextSupport = Json::Field<bool>(data, "contextSupport");
        ccc.insertTextMode = Json::Field<InsertTextMode>(data, "insertTextMode"
        );
        ccc.completionList = Json::Field<CompletionList>(data, "completionList"
        );
    }

    void to_json(nlohmann::json& data, const CompletionClientCapabilities& ccc)
    {
        if(ccc.dynamicRegistration.Present())
            data["dynamicRegistration"] = ccc.dynamicRegistration.Value();
        if(ccc.completionItem.Present())
            data["completionItem"] = ccc.completionItem.Value();
        if(ccc.completionItemKind.Present())
            data["completionItemKind"] = ccc.completionItemKind.Value();
        if(ccc.contextSupport.Present())
            data["contextSupport"] = ccc.contextSupport.Value();
        if(ccc.insertTextMode.Present())
            data["insertTextMode"] = ccc.insertTextMode.Value();
        if(ccc.completionList.Present())
            data["completionList"] = ccc.completionList.Value();
    }
}