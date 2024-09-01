#pragma once
#include <array>
#include <functional>

#include "NeuralNet.hpp"

#define NEURAL_NETWORKS_SIZE 1000

class NNTrainer {
public:
    NNTrainer();
    void train(const std::function<bool(NeuralNetwork)> condition, int repeats);
    void createChildren();
    int getMaxDeltaFitness();
private:
    std::array<NeuralNetwork, NEURAL_NETWORKS_SIZE> m_neuralNetworks;
};