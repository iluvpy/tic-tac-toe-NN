#include <iostream>

#include "TicTacToe.hpp"
#include "NNTrainer.hpp"

int main() { 

    std::array<int, BOARD_SIZE> board = TicTacToe::getRandomValidBoard();
    int i = 0;
    for (const auto& v : board) {
        std::cout << (v == CIRCLE ? 'O' : 'X') << " ";
        if (i && ((i+1) % 3) == 0) {
            std::cout << "\n";
        }
        i++;
    }
    // NNTrainer nnTrainer;

    // auto trainerFunction = [](NeuralNetwork neuralNetwork) {


    //     return false;
    // }
    // nnTrainer.train(trainerFunction, 100);

    
    return 0;   
}