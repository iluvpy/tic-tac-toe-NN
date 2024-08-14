#include <vector>


typedef struct {
    double value;
    std::vector<double> weights;
} Neuron;



// gets game state (whose turn it is and board) and returns the next best move
class NueralNetwork {
public:
    NueralNetwork() {

    }

    void mutate() {
        for (auto& weight : m_weights) {
            weight +
        }
    }    

private:
    std::vector<double> m_inputs;
    std::vector<double> m_weights;
    std::vector<double> m_biases;
};