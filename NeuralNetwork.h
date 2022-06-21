#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"

class NeuralNetwork
{
private:
    int numHiddenLayers;

    InputLayer* inputLayer;
    HiddenLayer* hiddenLayer;
    OutputLayer* outputLayer;
public:
    NeuralNetwork();

    void printNetwork();
    void clearNetwork();

    double forward(double* input);

    ~NeuralNetwork();
};

#endif