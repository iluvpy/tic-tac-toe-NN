#include "TicTacToe.hpp"
#include "Util.hpp"

TicTacToe::TicTacToe() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        m_board[i] = EMPTY;
    }
}

std::array<int, BOARD_SIZE> TicTacToe::getRandomValidBoard() {
    std::array<int, BOARD_SIZE> board;
    for (int i = 0; i < BOARD_SIZE; i++) board[i] = EMPTY;
    const int maxTurns = util::randomI(1, board.size()); 
    std::cout << "max turns: " << maxTurns << "\n";
    int currentTurn = util::randomI(0, 1) ? CROSS : CIRCLE;
    int i = 0;
    while (i < maxTurns) {
        auto indexes = TicTacToe::getEmptyIndex(board);  
        int randomEmptyIndex = util::randomI(0, indexes.size());
        board[indexes[randomEmptyIndex]] = currentTurn;
        currentTurn = currentTurn == CROSS ? CIRCLE : CROSS;
        i++;
        if (TicTacToe::isWinning(board)) {
            for (int i = 0; i < BOARD_SIZE; i++) board[i] = EMPTY;
            i = 0;
        }
    }
    return board;
}

bool TicTacToe::isValid(const std::array<int, BOARD_SIZE> &board) {
    int circles = 0;
    int crosses = 0;
    for (const auto& square : board) {
        if (square == CIRCLE) {
            circles++;
        } else if (square == CROSS) {
            crosses++;
        }
    }
    if (circles > crosses) return (circles - 1) == crosses;
    return (crosses - 1) == circles;
}


bool TicTacToe::isWinning(const std::array<int, BOARD_SIZE> &board) {
    static const int winning_positions[8][3] = {
        {0, 1, 2}, // Row 1
        {3, 4, 5}, // Row 2
        {6, 7, 8}, // Row 3
        {0, 3, 6}, // Column 1
        {1, 4, 7}, // Column 2
        {2, 5, 8}, // Column 3
        {0, 4, 8}, // Diagonal 1
        {2, 4, 6}  // Diagonal 2
    };

    for (const auto &pos : winning_positions) {
        int a = board[pos[0]], b = board[pos[1]], c = board[pos[2]];
        if (a != EMPTY && a == b && b == c) {
            return true;
        }
    }
    return false;
}

std::vector<int> TicTacToe::getEmptyIndex(const std::array<int, BOARD_SIZE> &board) {
    std::vector<int> emptySquares;
    int i = 0;
    for (const auto& square : board) {
        if (square == EMPTY) emptySquares.push_back(i);
        i++;
    }
    return emptySquares;
}
