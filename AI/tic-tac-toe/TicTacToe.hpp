#pragma once
#include <vector>

#define BOARD_SIZE 9

#define CIRCLE 1
#define CROSS 2
#define EMPTY 0
class TicTactoe {
public:
    TicTactoe() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            m_board[i] = EMPTY;
        }
    }
private:
    int m_currentTurn = 0;
    std::array<int, BOARD_SIZE> m_board;
}
