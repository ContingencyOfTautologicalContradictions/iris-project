#pragma once
#include <string>

namespace Iris::LSP
{
    auto Header(std::string&) noexcept -> void;

    [[nodiscard]] auto ContentLength(const std::string&) noexcept -> std::
    string;
}