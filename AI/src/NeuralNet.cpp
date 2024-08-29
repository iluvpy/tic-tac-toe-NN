#include <iostream>
#include <vector>
#include <algorithm>

#include "Util.hpp"
#include "NeuralNet.hpp"

#define MODEL_HEIGHT 9

// debugging preprocessors
#define DEBUG_MSG(x) std::cout << x;
#define DEBUG_VECTOR(x) std::cout << "vector " << #x << ";\n"; \
for (int i = 0; i < x.size(); i++) {std::cout << "i: " << i << " " << x[i] << "\n";}




Neuron::Neuron() {
    for (int i = 0; i < MODEL_HEIGHT; i++) {
        m_weights.push_back(util::random<double>(-3.0, 3.0));
    }
    m_bias = util::random<double>(-3.0, 3.0);
}


double Neuron::calculate(std::vector<double> inputs) const {
    double val = 0.0;
    for (int i = 0; i < inputs.size(); i++) {
        val += inputs[i] * m_weights[i];
    }
    return util::sigmoid(val + m_bias);
}

void Neuron::mutate() {
    for (auto& weight : m_weights) {
        weight += util::random<double>(-0.1, 0.1);
    }
    m_bias += util::random<double>(-0.1, 0.1);
}


void NeuralNetwork::generateNeuralNetwork(int numberOfLayers, int layerHeight) {
    DEBUG_MSG("generate Neural Net. was called!\n");
    if (m_layers.size() != 0) return;
    for (int i = 0; i < numberOfLayers; i++) {
        std::vector<Neuron> layer;
        for (int j = 0; j < layerHeight; j++) {
            layer.push_back(Neuron());
        }
        m_layers.push_back(layer);
    }
}

NeuralNetwork::NeuralNetwork() {
    constexpr int LAYER_HEIGHT = 9; // because the length of the boardstate is 9 
    constexpr int HIDDEN_LAYERS = 2;
    constexpr int OUTPUT_LAYER = 1; 

    generateNeuralNetwork(HIDDEN_LAYERS + OUTPUT_LAYER, LAYER_HEIGHT);
}




int NeuralNetwork::getTurn(std::vector<double> boardState) {
    DEBUG_MSG("called getTurn!\n");
    std::vector<double> values = boardState;
    DEBUG_VECTOR(values);
    int lowerBoundIndex = 0;
    int higherBoundIndex = 0;
    const auto& getInputValues = [](int lowerBoundIndex, int higherBoundIndex, std::vector<double> values) {
        std::vector<double> inputValues;
        for (int i = lowerBoundIndex; i < higherBoundIndex; i++) {
            inputValues.push_back(values[i]);
        }
        return inputValues;
    };
    for (const auto& layer : m_layers) {
        for (const auto& neuron : layer) {
            std::vector<double> inputs = getInputValues(lowerBoundIndex, higherBoundIndex, values);
            values.push_back(neuron.calculate(values));
        }
        lowerBoundIndex += layer.size();
        higherBoundIndex += layer.size();
        DEBUG_VECTOR(values);

    }

    std::vector<double> outputValues = getInputValues(lowerBoundIndex, higherBoundIndex, values);
    return std::distance(outputValues.begin(), std::max_element(outputValues.begin(), outputValues.end()));
}

void NeuralNetwork::mutate() {
    for (auto& layer : m_layers) {
        for (auto& neuron : layer) {
            neuron.mutate();
        } 
    }
}

