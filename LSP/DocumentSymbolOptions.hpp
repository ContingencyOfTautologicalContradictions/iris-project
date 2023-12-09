#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DocumentSymbolOptions final
    {
    public:
        Json::Field<bool> workDoneProgress;

        Json::Field<std::string> label;
    };

    void from_json(const nlohmann::json&, DocumentSymbolOptions&);

    void to_json(nlohmann::json&, const DocumentSymbolOptions&);
}