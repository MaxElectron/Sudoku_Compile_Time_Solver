#pragma once

#include <cstddef>
#include <type_traits>

namespace arithmetic_ct
{
    template <std::size_t N, size_t I = 1, typename = void>
    struct int_sqrt
    {
        static constexpr size_t value = int_sqrt<N, I + 1>::value;
    };

    template <size_t N, size_t I>
    struct int_sqrt<N, I, typename std::enable_if<(I * I >= N)>::type>
    {
        static constexpr size_t value = (I * I == N) ? I : 0;
    };
}