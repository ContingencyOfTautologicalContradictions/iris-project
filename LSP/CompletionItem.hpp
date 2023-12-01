#pragma once
#include "MarkupKind.hpp"
#include "TagSupport.hpp"
#include "../JSON/Field.hpp"
#include "ResolveSupport.hpp"
#include "InsertTextModeSupport.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CompletionItem final
    {
    public:
        Json::Field<bool> snippetSupport, commitCharactersSupport;

        Json::Field<std::vector<MarkupKind>> documentationFormat;

        Json::Field<bool> deprecatedSupport, preselectSupport;

        Json::Field<TagSupport> tagSupport;

        Json::Field<bool> insertReplaceSupport;

        Json::Field<ResolveSupport> resolveSupport;

        Json::Field<InsertTextModeSupport> insertTextModeSupport;

        Json::Field<bool> labelDetailsSupport;
    };

    void from_json(const nlohmann::json&, CompletionItem&);

    void to_json(nlohmann::json&, const CompletionItem&);
}