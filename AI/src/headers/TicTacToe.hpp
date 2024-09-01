#pragma once
#include <vector>
#include <algorithm>
#include <array>
#include <iostream>

#define BOARD_SIZE 9

#define CIRCLE 1
#define CROSS 2
#define EMPTY 0

class TicTacToe {
public:
    TicTacToe();
    /*
        @brief generates a random game state of tic tac toe that is valid
    */
    static std::array<int, BOARD_SIZE> getRandomValidBoard();
    /*
        @brief checks if array board is a valid game state for tic tac toe
    */
    static bool isValid(const std::array<int, BOARD_SIZE> &board);
    /*
        @brief checks if board state is a winning position for either cross or circle
    */
    static bool isWinning(const std::array<int, BOARD_SIZE> &board);
    /*
        @brief returns a list of indexes that point to empty squares in board array
    */
    static std::vector<int> getEmptyIndex(const std::array<int, BOARD_SIZE> &board);


private:
    //int m_currentTurn = 0;
    int m_board[BOARD_SIZE];
};
