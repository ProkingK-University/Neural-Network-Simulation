#include <math.h>

#include "HiddenLayer.h"

HiddenNeuron::HiddenNeuron(int numWeights, double* weights) : numWeights(numWeights)
{
    value = 0;

    this->weights = weights;
}

void HiddenNeuron::activateReLU()
{
    
    value = std::max(0.0, value);
}

void HiddenNeuron::activateSigmoid()
{
    value = 1 / 1 + exp(-value);
}

void HiddenNeuron::setValue(double value)
{
    this->value = value;
}

void HiddenNeuron::forward(HiddenLayer* prevLayer)
{
    double total = 0;
    HiddenNeuron** prevNeurons = prevLayer->getNeurons();

    for (int i = 0; i < numWeights; i++)
    {
        total += prevNeurons[i]->value * weights[i];
    }
     
    value = total;
}

void HiddenNeuron::forward(InputLayer* inputLayer)
{
    double total = 0;
    double* inputs = inputLayer->getInputs();

    for (int i = 0; i < inputLayer->getNumInputs(); i++)
    {
        total += inputs[i] * weights[i];
    }
     
    value = total;
}

double HiddenNeuron::getValue()
{
    return value;
}

HiddenNeuron::~HiddenNeuron()
{
    for (int i = 0; i < numWeights; i++) 
    {
        weights[i] = NULL;
    }
    delete [] weights;
}

//(;