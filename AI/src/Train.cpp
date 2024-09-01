#include <iostream>

#include "TicTacToe.hpp"
#include "NNTrainer.hpp"

int main() { 

    std::array<int, BOARD_SIZE> board = TicTacToe::getRandomValidBoard();
    int i = 0;
    for (const auto& v : board) {
        char ch = (v == CIRCLE ? 'O' : 'X');
        if (v == EMPTY) ch = '-';
        std::cout << ch << " ";
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