#pragma once

#include <type_traits>

#include "template_magic.hpp"

namespace sudoku_cts
{
    template <int... Board>
    struct guess_check
    {
        static constexpr bool is_valid = true;
    };

    template <int... Board>
    struct next_guess
    {
        using result = template_magic::board_state<Board...>;
    };

    template <int... Board>
    struct initial_validator
    {
        static constexpr bool is_valid = true;
    };

    template <int... Board>
    struct iterative_solver
    {
        using iterated_board = typename next_guess<Board...>::result;
        static constexpr bool is_valid_guess = template_magic::unpack_variadic<iterated_board, guess_check>::type::is_valid;
        using result = typename std::conditional<is_valid_guess, iterated_board, template_magic::failed_solution>::type;
    };

    template <bool Is_valid, int... Board>
    struct valid_board_solver
    {
        using result = template_magic::failed_solution;
    };

    template <int... Board>
    struct valid_board_solver<true, Board...>
    {
        using result = typename iterative_solver<Board...>::result;
    };

    template <int... Board>
    struct solver
    {
        using result = typename valid_board_solver<initial_validator<Board...>::is_valid, Board...>::result;
        static constexpr auto value = template_magic::unpack_variadic<result, template_magic::identity>::type::value;
    };
}