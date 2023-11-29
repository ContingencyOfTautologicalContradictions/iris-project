#pragma once
#include "Same.hpp"
#include "../JSON/Json.hpp"

namespace Iris::Meta
{
    template<class T> concept Serialisable = requires (const nlohmann::json& data)
    {
        {data.get<T>()} -> Meta::Same<T>;
    };
}