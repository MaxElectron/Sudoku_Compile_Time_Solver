#pragma once

#include <array>
#include <iostream>

constexpr char separator = '#';

template <size_t Board_size>
void print_board(const std::array<int, Board_size> &board)
{
    constexpr size_t N = arithmetic_ct::int_sqrt<Board_size>::value;
    constexpr size_t N_sqrt = arithmetic_ct::int_sqrt<N>::value;
    for (size_t block_r = 0; block_r < N_sqrt; ++block_r)
    {
        for (size_t inner_r = 0; inner_r < N_sqrt; ++inner_r)
        {
            const size_t r = block_r * N_sqrt + inner_r;
            for (size_t block_c = 0; block_c < N_sqrt; ++block_c)
            {
                for (size_t inner_c = 0; inner_c < N_sqrt; ++inner_c)
                {
                    const size_t c = block_c * N_sqrt + inner_c;
                    std::cout << board[r * N + c] << " ";
                }
                if (block_c < N_sqrt - 1)
                {
                    std::cout << separator << " ";
                }
            }
            std::cout << "\n";
        }
        if (block_r < N_sqrt - 1)
        {
            for (size_t i = 0; i < N_sqrt; ++i)
            {
                for (size_t j = 0; j < N_sqrt; ++j)
                {
                    std::cout << separator << " ";
                }
                if (i < N_sqrt - 1)
                {
                    std::cout << separator << " ";
                }
            }
            std::cout << "\n";
        }
    }
}