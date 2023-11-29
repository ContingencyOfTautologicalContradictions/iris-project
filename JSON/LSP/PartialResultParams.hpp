#pragma once
#include "ProgressParams.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] PartialResultParams final
    {
    public:
        Json::Field<ProgressToken> partialResultToken;
    };

    void from_json(const nlohmann::json&, PartialResultParams&);

    void to_json(nlohmann::json&, const PartialResultParams&);
}