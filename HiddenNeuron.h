#ifndef HIDDEN_NEURON_H
#define HIDDEN_NEURON_H

#include "InputLayer.h"
#include "HiddenLayer.h"

class HiddenNeuron
{
private:
    double value;
    double* weights;

    int numWeights;
public:
    HiddenNeuron();

    void activateReLU();
    void activateSigmoid();
    void setValue(double value);
    void forward(InputLayer* inputLayer);
    void forward(HiddenLayer* prevLayer);

    double getValue();

    ~HiddenNeuron();
};

#endif
