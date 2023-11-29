#include "Command.hpp"

namespace Iris::LSP
{
    void from_json(const nlohmann::json& data, Command& c)
    {
        c.title = data.at("titile").get<std::string>();
        c.command = data.at("command").get<std::string>();
        if(data.contains("arguments"))
        {
            c.arguments.Set();
            const nlohmann::json& arguments = data.at("arguments");
            for(const nlohmann::json& argument : arguments)
            {
                if(argument.is_null())
                    c.arguments.Value().push_back(Command::Arguments{});
                else if(argument.is_number_integer())
                    c.arguments.Value().push_back(argument.get<std::int64_t>())
                    ;
                else if(argument.is_string())
                    c.arguments.Value().push_back(argument.get<std::string>());
                else if(argument.is_boolean())
                    c.arguments.Value().push_back(argument.get<bool>());
            }
        }
    }

    [[nodiscard]] auto jsonify(const std::vector<Command::Arguments>& arguments
    ) noexcept -> nlohmann::json
    {
        nlohmann::json data;
        for(const Command::Arguments& argument : arguments)
        {
            if(argument.has_value())
                std::visit([&](auto&& active)
                {
                    data.push_back(active);
                }, argument.value());
            else
                data.push_back(nullptr);
        }
        return data;
    }

    void to_json(nlohmann::json& data, const Command& c)
    {
        data["title"] = c.title;
        data["command"] = c.command;
        if(c.arguments.Present())
            data["arguments"] = jsonify(c.arguments.Value());
    }
}