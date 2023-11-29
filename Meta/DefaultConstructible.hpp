#pragma once

namespace Iris::Meta
{
    template<class T> concept DefaultConstructible = __is_constructible(T);
}