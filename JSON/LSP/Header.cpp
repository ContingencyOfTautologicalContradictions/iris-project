#include "Header.hpp"

namespace Iris::LSP
{
    auto Header(std::string& header) noexcept -> void
    {
        std::size_t x = 0z;
        while(header[x] != '{')
            ++x;
        header.erase(0z, x);
    }

    [[nodiscard]] auto ContentLength(const std::string& content) noexcept ->
    std::string
    {
        std::string result = "Content-Length: ";
        result += content.size();
        result += "\r\n";
        result += content;
        return result;
    }
}