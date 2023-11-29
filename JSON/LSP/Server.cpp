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
            while(std::getline(std::cin, line)) //ohno{"jsonrpc":"2.0", "method":"$/cancelRequest", "params":{"id":"meow"}}
                request += line;
            Header(request);
            const nlohmann::json data = nlohmann::json::parse(request);
            if(data.is_object())
                std::cout << data.template get<Message>().Respond();
        }
    }
}