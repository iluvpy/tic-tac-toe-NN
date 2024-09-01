#include "NNTrainer.hpp"


NNTrainer::NNTrainer() {}

void NNTrainer::train(const std::function<bool(NeuralNetwork)> condition, int repeats) {
    for (auto& neuralNetwork : m_neuralNetworks) {
        int deltaFitness = 0;
        for (int i = 0; i < repeats; i++) {
            if (condition(neuralNetwork)) {
                deltaFitness += 10;
            } else {deltaFitness += -10;}
        }
        neuralNetwork.addFitness(deltaFitness);
    }
}

void NNTrainer::createChildren() {

}

int NNTrainer::getMaxDeltaFitness() {
    int max = 0;
    for (const auto& neuralNetwork : m_neuralNetworks) {
        if (neuralNetwork.getFitness() > max) {
            max = neuralNetwork.getFitness();
        }
    }
    return max;
}
