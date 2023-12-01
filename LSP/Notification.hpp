#pragma once
#include "CancelParams.hpp"
#include "ProgressParams.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Notification final
    {
    public:
        std::string jsonrpc, method;

        Json::Field<std::vector<std::variant<CancelParams, ProgressParams>>>
        params;
    };

    void from_json(const nlohmann::json&, Notification&);

    void to_json(nlohmann::json&, const Notification&);
}