#include "PositionEncoding.hpp"

namespace Iris::LSP
{
    [[nodiscard]] auto PositionEncodingKind(PositionEncoding pe) noexcept ->
    std::string
    {
        switch(pe)
        {
            using enum PositionEncoding;
            case UTF8:
                return "utf-8";
            case UTF16:
                return "utf-16";
            case UTF32:
                return "utf-32";
        }
    }
}