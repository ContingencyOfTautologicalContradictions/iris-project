#pragma once
#include <string>
#include <variant>

namespace Iris::LSP
{
    using ProgressToken = std::variant<std::int64_t, std::string>;
}