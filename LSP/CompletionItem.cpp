#include "CompletionItem.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, CompletionItem& ci)
    {
        ci.snippetSupport = Json::Field<bool>(data, "snippetSupport");
        ci.commitCharactersSupport = Json::Field<bool>(data,
        "commitCharactersSupport");
        ci.documentationFormat = Json::Field<std::vector<MarkupKind>>(data,
        "documentationFormat");
        ci.deprecatedSupport = Json::Field<bool>(data, "deprecatedSupport");
        ci.preselectSupport = Json::Field<bool>(data, "preselectSupport");
        ci.tagSupport = Json::Field<TagSupport>(data, "tagSupport");
        ci.insertReplaceSupport = Json::Field<bool>(data,
        "insertReplaceSupport");
        ci.resolveSupport = Json::Field<ResolveSupport>(data, "resolveSupport")
        ;
        ci.insertTextModeSupport = Json::Field<InsertTextModeSupport>(data,
        "insertTextModeSupport");
        ci.labelDetailsSupport = Json::Field<bool>(data, "labelDetailsSupport")
        ;
    }

    void to_json(nlohmann::json& data, const CompletionItem& ci)
    {
        if(ci.snippetSupport.Present())
            data["snippetSupport"] = ci.snippetSupport.Value();
        if(ci.commitCharactersSupport.Present())
            data["commitCharactersSupport"] = ci.commitCharactersSupport.Value(
            );
        if(ci.documentationFormat.Present())
            data["documentationFormat"] = ci.documentationFormat.Value();
        if(ci.deprecatedSupport.Present())
            data["deprecatedSupport"] = ci.deprecatedSupport.Value();
        if(ci.preselectSupport.Present())
            data["preselectSupport"] = ci.preselectSupport.Value();
        if(ci.tagSupport.Present())
            data["tagSupport"] = ci.tagSupport.Value();
        if(ci.insertReplaceSupport.Present())
            data["insertReplaceSupport"] = ci.insertReplaceSupport.Value();
        if(ci.resolveSupport.Present())
            data["resolveSupport"] = ci.resolveSupport.Value();
        if(ci.insertTextModeSupport.Present())
            data["insertTextModeSupport"] = ci.insertTextModeSupport.Value();
        if(ci.labelDetailsSupport.Present())
            data["labelDetailsSupport"] = ci.labelDetailsSupport.Value();
    }
}