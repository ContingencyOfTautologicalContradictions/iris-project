#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextDocumentFilter final
    {
    public:
        Json::Field<std::string> notebookType, scheme, pattern;
    };

    void from_json(const nlohmann::json&, TextDocumentFilter&);

    void to_json(nlohmann::json&, const TextDocumentFilter&);
}