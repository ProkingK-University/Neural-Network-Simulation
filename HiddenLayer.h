#ifndef HIDDEN_LAYER_H
#define HIDDEN_LAYER_H

#include <iostream>

#include "InputLayer.h"
#include "HiddenLayer.h"
#include "HiddenNeuron.h"

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
    void forward(InputLayer* inputLayer);
    void forward(HiddenLayer* prevLayer);
    void setNeurons(HiddenNeuron** neurons);

    int getNumNeurons();

    HiddenNeuron** getNeurons();

    ~HiddenLayer();
};

#endif