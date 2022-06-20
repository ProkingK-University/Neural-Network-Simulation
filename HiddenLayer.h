#ifndef HIDDEN_LAYER_H
#define HIDDEN_LAYER_H

#include <iostream>

#include "InputLayer.h"
#include "HiddenLayer.h"
#include "HiddenNeuron.h"

class HiddenLayer
{
private:
    int numNueurons;
    std::string activation;
    HiddenNeuron** neurons;
public:;
    HiddenLayer();

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