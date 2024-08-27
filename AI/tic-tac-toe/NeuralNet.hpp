#pragma once
#include <iostream>
#include <vector>

#include "Util.hpp"


class Neuron {
public:
    Neuron(const Neuron &neuron) {
        (*this) = neuron;
    }

    Neuron(int inputs) {
        for (int i = 0; i < inputs; i++) {
            m_weights.push_back(util::random<double>(-3.0, 3.0));
        }
        m_bias = util::random<double>(-3.0, 3.0);
    }

    double calculate(std::vector<double> inputs) {
        double val = 0.0;
        for (int i = 0; i < inputs.size(); i++) {
            val += inputs[i] * m_weights[i];
        }
        return util::sigmoid(val + m_bias);
    }

    void mutate() {
        for (auto& weight : m_weights) {
            weight += util::random<double>(-0.1, 0.1);
        }
        m_bias += util::random<double>(-0.1, 0.1);
    }

    Neuron getChild() {
        Neuron child(*this);
        child.mutate();
        return child;
    }

private:

    std::vector<double> m_weights;
    double m_bias;
};

// gets game state (whose turn it is and board) and returns the next best move
class NueralNetwork {
public:

    NueralNetwork(bool isCircle, int layers, int inputSize=9) {
        m_isCircle = isCircle;
        m_layers = layers;
        generateNN(inputSize);
    }

    int getTurn(std::vector<double> inputs) {
        std::vector<double> values;
        for (int i = 0; i < m_neuronLayers.size(); i++) {
            std::vector<double> values_copy;
            std::vector<Neuron> layer = m_neuronLayers[i];
            for (int j = 0; j < layer.size(); j++) {
                double v;
                if (i) {
                    v = layer[j].calculate(values);
                    values_copy.push_back(v);
                } else {
                    v = layer[j].calculate(inputs);
                }
                values.push_back(v);
            }
            if (i) {
                values = values_copy;
            }
        }
        int index = 0;
        int max = 0;
        for (int i = 0; i < values.size(); i++) {
            if (values[i] > max) {
                max = values[i];
                index = i;
            }
        }
        return index; // best move
    }   

    std::vector<std::vector<Neuron>> getLayers() {
        return m_neuronLayers;
    }

private:

    void generateNN(int inputSize) {
        for (int i = 0; i < m_layers; i++) {
            std::vector<Neuron> layer;
            for (int j = 0; j < inputSize; j++) {
                layer.push_back(Neuron(9));
            }
            m_neuronLayers.push_back(layer);
        }

    }

    bool m_isCircle;
    int m_layers;
    std::vector<std::vector<Neuron>> m_neuronLayers;

};