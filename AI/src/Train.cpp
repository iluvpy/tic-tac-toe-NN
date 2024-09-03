#include <iostream>

#include "TicTacToe.hpp"
#include "NNTrainer.hpp"

int main() { 
    NNTrainer nnTrainer;

    auto trainerFunction = [](const NeuralNetwork &neuralNetwork) {
        std::array<int, BOARD_SIZE> board; // generate a board with possible moves
        do { board = TicTacToe::getRandomValidBoard();} 
        while (TicTacToe::getEmptyIndexes(board).size() <= 0);

        std::vector<int> freeMoves = TicTacToe::getEmptyIndexes(board);
        int index = neuralNetwork.getTurn(board);
        bool choseEmptySquare = std::find(freeMoves.begin(), freeMoves.end(), index) != freeMoves.end();
        
        return choseEmptySquare;
    };
    nnTrainer.train(trainerFunction, 100);

    
    return 0;   
}