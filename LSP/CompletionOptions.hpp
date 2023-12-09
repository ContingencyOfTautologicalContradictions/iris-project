#pragma once
#include "CompletionItem2.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CompletionOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        Json::Field<std::vector<std::string>> triggerCharacters,
        allCommitCharacters;

        Json::Field<bool> resolveProvider;

        Json::Field<CompletionItem2> completionItem;
    };

    void from_json(const nlohmann::json&, CompletionOptions&);

    void to_json(nlohmann::json&, const CompletionOptions&);
}