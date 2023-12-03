#pragma once
#include "ShowDocumentClientCapabilities.hpp"
#include "ShowMessageRequestClientCapabilities.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Window final
    {
    public:
        Json::Field<bool> workDoneProgress;

        Json::Field<ShowMessageRequestClientCapabilities> showMessage;

        Json::Field<ShowDocumentClientCapabilities> showDocument;
    };

    void from_json(const nlohmann::json&, Window&);

    void to_json(nlohmann::json&, const Window&);
}