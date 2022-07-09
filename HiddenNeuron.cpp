#include <math.h>

#include "HiddenNeuron.h"
#include "HiddenLayer.h"

HiddenNeuron::HiddenNeuron(int numWeights, double* weights) : numWeights(numWeights)
{
    value = 0;

    this->weights = weights;
}

//Calculation for ReLU activation

void HiddenNeuron::activateReLU()
{
    
    value = std::max(0.0, value);
}

//Calculation for Sigmoid activation

void HiddenNeuron::activateSigmoid()
{
    value = 1 / (1 + exp(-value));
}

void HiddenNeuron::setValue(double value)
{
    this->value = value;
}

//Calculation for value of neuron

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

//Calculation for value of neuron in the first hidden layer

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
        weights[i] = 0;
    }
    delete [] weights;
}

//(;