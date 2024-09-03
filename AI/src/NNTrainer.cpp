#include "NNTrainer.hpp"


NNTrainer::NNTrainer() {}

void NNTrainer::train(const std::function<bool(const NeuralNetwork&)> condition, int repeats) {
    std::cout << "called NNtrainer::train\n";
    int neuralNetIndex = 0;
    for (auto& neuralNetwork : m_neuralNetworks) {
        int deltaFitness = 0;
        for (int i = 0; i < repeats; i++) {
            if (condition(neuralNetwork)) {

                deltaFitness += 10;
            } else {deltaFitness += -10;}
        }
        std::cout << "adding delta Fitness to neural network\n";
        neuralNetIndex++;
        std::cout << "neural network " << neuralNetIndex << " has been tested!\n";
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
