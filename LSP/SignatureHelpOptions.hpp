#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] SignatureHelpOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        Json::Field<std::vector<std::string>> triggerCharacters,
        retriggerCharacters;
    };

    void from_json(const nlohmann::json&, SignatureHelpOptions&);

    void to_json(nlohmann::json&, const SignatureHelpOptions&);
}