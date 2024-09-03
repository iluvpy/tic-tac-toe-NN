#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "TicTacToe.hpp"

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

    int getTurn(std::array<int, BOARD_SIZE> boardState) const;
    void addFitness(int val);
    int getFitness() const;
    void mutate();
};