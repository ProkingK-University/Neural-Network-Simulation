#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "OutputLayer.h"

class NeuralNetwork
{
private:
    int numHiddenLayers;

    InputLayer* inputLayer;
    HiddenLayer** hiddenLayers;
    OutputLayer* outputLayer;
public:
    NeuralNetwork(std::string filePath);

    void printNetwork();
    void clearNetwork();

    double forward(double* input);

    ~NeuralNetwork();
};

#endif