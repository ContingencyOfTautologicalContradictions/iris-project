#pragma once
#include "../JSON/Field.hpp"
#include "TextDocumentSyncKind.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] TextDocumentSyncOptions final
    {
    public:
        Json::Field<bool> openClose;

        Json::Field<TextDocumentSyncKind> change;
    };

    void from_json(const nlohmann::json&, TextDocumentSyncOptions&);

    void to_json(nlohmann::json&, const TextDocumentSyncOptions&);
}