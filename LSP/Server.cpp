#include "Server.hpp"
#include "Header.hpp"
#include "Message.hpp"
#include <iostream>
#include <fstream>

namespace Iris::LSP
{
    auto Process() noexcept -> void
    {
        bool process = true;
        while(process)
        {
            std::string request, line;
            while(std::getline(std::cin, line))
                request += line;
            Header(request);
            const nlohmann::json data = nlohmann::json::parse(request);
            if(data.is_object())
                std::cout << data.template get<Message>().Respond();
        }
    }
}