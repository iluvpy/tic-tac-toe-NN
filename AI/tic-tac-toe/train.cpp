#include <iostream>
#include "NeuralNet.hpp"

class NNTrainer {
public:

private:
    
};

int main() {
    NueralNetwork nn(false, 3, 9);
    std::vector<double> board = {
        1, 0, 1,
        1, 0, 2,
        2, 0, 0
    };

    int turn = nn.getTurn(board);
    std::cout << turn << "\n";
    
    std::vector<std::vector<Neuron>> layers = nn.getLayers();

}