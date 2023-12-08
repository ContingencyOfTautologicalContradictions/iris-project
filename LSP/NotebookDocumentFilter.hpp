#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] NotebookDocumentFilter final
    {
    public:
        Json::Field<std::string> notebookType, scheme, pattern;
    };

    void from_json(const nlohmann::json&, NotebookDocumentFilter&);

    void to_json(nlohmann::json&, const NotebookDocumentFilter&);
}