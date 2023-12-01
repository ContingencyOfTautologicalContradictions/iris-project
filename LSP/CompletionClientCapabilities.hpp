#pragma once
#include "CompletionItem.hpp"
#include "CompletionList.hpp"
#include "CompletionItemKind.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CompletionClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration;

        Json::Field<CompletionItem> completionItem;

        Json::Field<CompletionItemKind> completionItemKind;

        Json::Field<bool> contextSupport;

        Json::Field<InsertTextMode> insertTextMode;

        Json::Field<CompletionList> completionList;
    };

    void from_json(const nlohmann::json&, CompletionClientCapabilities&);

    void to_json(nlohmann::json&, const CompletionClientCapabilities&);
}