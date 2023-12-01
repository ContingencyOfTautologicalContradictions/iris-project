#pragma once
#include "URI.hpp"
#include "Range.hpp"
#include "../JSON/Field.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] LocationLink final
    {
    public:
        Json::Field<Range> originSelectionRange;

        DocumentUri targetUri;

        Range targetRange, targetSelectionRange;
    };

    void from_json(const nlohmann::json&, LocationLink&);

    void to_json(nlohmann::json&, const LocationLink&);
}