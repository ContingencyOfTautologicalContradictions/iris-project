#pragma once
#include "Request.hpp"
#include "Notification.hpp"

namespace Iris::LSP
{
    class [[nodiscard]] Message final
    {
    public:
        std::variant<Request, Notification> value;

        [[nodiscard]] auto Respond() const noexcept -> std::string;
    };

    void from_json(const nlohmann::json&, Message&);
}