#pragma once

#include <array>
#include <type_traits>

namespace template_magic
    {
        template <int... Board>
        struct identity
        {
            static constexpr std::array<int, sizeof...(Board)> value = {Board...};
        };

        struct failed_solution {};

        template <int... Vals>
        struct board_state {};

        template <typename Packaged_args, template<auto...> typename Insertion_target, auto... Leading_args>
        struct unpack_variadic;

        template <template<auto...> class Package, template<auto...> typename Insertion_target, auto... Leading_args, auto... Vals>
        struct unpack_variadic<Package<Vals...>, Insertion_target, Leading_args...>
        {
            using type = Insertion_target<Leading_args..., Vals...>;
        };
    }