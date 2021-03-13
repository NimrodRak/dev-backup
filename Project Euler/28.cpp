#include "gmacro.h"
#include <array>

#define SIZE 1001

using board_t = std::array<std::array<int, SIZE>, SIZE>;

bool inline is_valid(size_t row, size_t col, size_t size) { return row >= 0 && col >= 0 && col < size && row < size; }

bool inline is_empty(int **board, size_t row, size_t col, short row_change, short col_change)
{ return !is_valid(row + row_change, col + col_change, SIZE) || board[row + row_change][col + col_change] == 0; }

#define mini_empty(rc, cc) is_empty(board, row, col, rc, cc)

int main()
{
    //board_t board;
    int** board = new int* [SIZE];
    for (size_t i = 0; i < SIZE; ++i)
        board[i] = new int[SIZE]{0};
    
    size_t row = SIZE / 2, col = SIZE / 2;

    board[row][col] = 1;
    col++;

    for (size_t i = 2; is_valid(row, col, SIZE); ++i)
    {
        // set the current value
        board[row][col] = i;
        // log (row << ' ' << col);
        // for (auto& x : board)
        // {
        //     for (auto y : x)
        //         std::cout << y << ' ';
        //     std::cout << std::endl;
        // }
        if (mini_empty(-1, 0) && mini_empty(1, 0) && mini_empty(0, 1)) // top right
            ++row;
        
        else if (mini_empty(0, 1) && mini_empty(1, 0) && mini_empty(0, -1)) // bottom right
            --col;
        
        else if (mini_empty(0, -1) && mini_empty(-1, 0) && mini_empty(1, 0)) // bottom left
            --row;
        
        else if (mini_empty(-1, 0) && mini_empty(0, 1) && mini_empty(0, -1)) // top left
            ++col;

        // down
        else if (mini_empty(1, 0) && mini_empty(0, 1))
            ++row;

        // left
        else if (mini_empty(1, 0) && mini_empty(0, -1))
            --col;
        
        // up
        else if (mini_empty(-1, 0), mini_empty(0, -1))
            --row;
        
        // right
        else if (mini_empty(-1, 0), mini_empty(0, 1))
            ++col;
    }
    long long total = 0;
    for (size_t i = 0; i < SIZE; ++i)
    {
        total += board[i][i];
        if (i != SIZE / 2)
            total += board[i][SIZE - i - 1];        
    }
    // for (auto& x : board)
    // {
    //     for (auto y : x)
    //         std::cout << y << ' ';
    //     std::cout << std::endl;
    // }
    log(total);
    // std::cin.get();
        
}