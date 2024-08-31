#include <iostream>
#include <vector>
#include <array>

#include "NeuralNet.hpp"


#define NEURAL_NETWORKS_SIZE 1000



class NNTrainer {
public:

    NNTrainer() {

    }

private:
    std::array<NeuralNetwork, NEURAL_NETWORKS_SIZE> m_neuralNetworks;
};

int main() {
 
    NNTrainer nnTrainer;
    
    return 0;
}