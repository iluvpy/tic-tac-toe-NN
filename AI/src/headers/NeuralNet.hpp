#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#define MODEL_HEIGHT 9

class Neuron {
private:

    std::vector<double> m_weights;
    double m_bias;

public:
    Neuron();

    double calculate(std::vector<double> inputs) const;
    void mutate();
};

class NeuralNetwork {
private:
    std::vector<std::vector<Neuron>> m_layers;
    //bool isCircle; // if the ai is playing circle
    int m_fitness;

    void generateNeuralNetwork(int numberOfLayers, int layerHeight);

public:
    NeuralNetwork();

    int getTurn(std::vector<double> boardState);
    void addFitness(int val);
    int getFitness() const;
    void mutate();
};