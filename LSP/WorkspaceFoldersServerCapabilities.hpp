#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] WorkspaceFoldersServerCapabilities final
    {
    public:
        Json::Field<bool> supported;

        Json::Field<std::variant<bool, std::string>> changeNotifications;
    };

    void from_json(const nlohmann::json&, WorkspaceFoldersServerCapabilities&);

    void to_json(nlohmann::json&, const WorkspaceFoldersServerCapabilities&);
}