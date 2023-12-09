#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] CodeActionOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        Json::Field<std::vector<std::string>> codeActionKinds;

        Json::Field<bool> resolveProvider;
    };

    void from_json(const nlohmann::json&, CodeActionOptions&);

    void to_json(nlohmann::json&, const CodeActionOptions&);
}