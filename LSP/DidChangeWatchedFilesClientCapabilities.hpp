#pragma once
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] DidChangeWatchedFilesClientCapabilities final
    {
    public:
        Json::Field<bool> dynamicRegistration, relativePatternSupport;
    };

    void from_json(const nlohmann::json&,
    DidChangeWatchedFilesClientCapabilities&);

    void to_json(nlohmann::json&, const DidChangeWatchedFilesClientCapabilities
    &);
}