#pragma once
#include "Cells.hpp"
#include "NotebookDocumentFilter.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] NotebookSelector final
    {
    public:
        Json::Field<std::variant<std::string, NotebookDocumentFilter>> notebook
        ;

        Json::Field<std::vector<Cells>> cells;
    };

    void from_json(const nlohmann::json&, NotebookSelector&);

    void to_json(nlohmann::json&, const NotebookSelector&);
}