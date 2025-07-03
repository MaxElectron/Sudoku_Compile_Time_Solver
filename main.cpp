#include "arithmetic_ct.hpp"
#include "print_board.hpp"
#include "sudoku_cts.hpp"

int main()
{
    constexpr auto solved_board = sudoku_cts::solver<
        1, 2, 3, 4,
        3, 4, 1, 2,
        2, 1, 4, 3,
        4, 3, 2, 1
    >::value;

    print_board(solved_board);
}