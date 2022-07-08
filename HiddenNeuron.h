#ifndef HIDDENNEURON_H
#define HIDDENNEURON_H

#include <iostream>

#include "InputLayer.h"

class HiddenLayer;

class HiddenNeuron
{
private:
    double value;
    double* weights;

    int numWeights;
public:
    HiddenNeuron(int numWeights, double* weights);

    void activateReLU();
    void activateSigmoid();
    void setValue(double value);
    void forward(HiddenLayer* prevLayer);
    void forward(InputLayer* inputLayer);

    double getValue();

    ~HiddenNeuron();
};

#endif
