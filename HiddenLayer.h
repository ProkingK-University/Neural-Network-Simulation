#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H

#include <iostream>

#include "InputLayer.h"

class HiddenNeuron;

class HiddenLayer
{
private:
    int numNeurons;
    std::string activation;
    HiddenNeuron** neurons;
public:;
    HiddenLayer(int numNeurons, HiddenNeuron** neurons, std::string activation);

    void printLayer();
    void clearLayer();
    void setNumNeurons(int numNeurons);
    void forward(HiddenLayer* prevLayer);
    void forward(InputLayer* inputLayer);
    void setNeurons(HiddenNeuron** neurons);

    int getNumNeurons();

    HiddenNeuron** getNeurons();

    ~HiddenLayer();
};

#endif