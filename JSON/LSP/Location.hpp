#pragma once
#include "URI.hpp"
#include "Range.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Location final
    {
    public:
        DocumentUri uri;

        Range range;
    };

    void from_json(const nlohmann::json&, Location&);

    void to_json(nlohmann::json&, const Location&);
}