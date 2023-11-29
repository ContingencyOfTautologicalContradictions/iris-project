#include "Message.hpp"

namespace Iris::LSP
{
    [[nodiscard]] auto Message::Respond() const noexcept -> std::string
    {
        nlohmann::json response;
        std::visit([&](auto&& active)
        {
            to_json(response, active);
        }, value);
        return response.dump();
    }

    void from_json(const nlohmann::json& data, Message& m)
    {
        if(data.contains("id"))
            m.value = data.get<Request>();
        else
            m.value = data.get<Notification>();
    }
}