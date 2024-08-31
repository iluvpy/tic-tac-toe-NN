#pragma once

#define MODEL_HEIGHT 9

// debugging preprocessors
#define DEBUG_MSG(x) std::cout << x;
#define DEBUG_VECTOR(x) std::cout << "vector " << #x << ";\n"; \
for (int i = 0; i < x.size(); i++) {std::cout << "i: " << i << " " << x[i] << "\n";}

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

    void generateNeuralNetwork(int numberOfLayers, int layerHeight);

public:
    NeuralNetwork();

    int getTurn(std::vector<double> boardState);
    void mutate();
};