#include <iostream>
#include <vector>

#include "NeuralNet.hpp"

class NNTrainer {
public:

private:
    
};

int main() {

    NeuralNetwork nn;
    std::vector<double> board = {
        1, 0, 1,
        1, 0, 2,
        2, 0, 0
    };

    int turn = nn.getTurn(board);
    std::cout << turn << "\n";

}