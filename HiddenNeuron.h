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
