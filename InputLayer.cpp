#include <iostream>

#include "InputLayer.h"

InputLayer::InputLayer(int numInputs) : numInputs(numInputs)
{
    inputs = NULL;
}

void InputLayer::printLayer()
{
    std::cout<< "i:" << numInputs <<std::endl;
}

void InputLayer::clearLayer()
{
    if (inputs != NULL)
    {
        for (int i = 0; i < numInputs; i++)
        {
            inputs[i] = 0;
        }
    }
}

void InputLayer::setInputs(double* inputs)
{
    if (this->inputs != NULL)
    {
        for (int i = 0; i < numInputs; i++) 
        {
            this->inputs[i] = 0;
        }
        delete [] this->inputs;
    }

    this->inputs = inputs;
}

void InputLayer::setNumInputs(int numInputs)
{
    this->numInputs = numInputs;
}

int InputLayer::getNumInputs()
{
    return numInputs;
}

double* InputLayer::getInputs()
{
    return inputs;
}

InputLayer::~InputLayer()
{
    if (inputs != NULL)
    {
        for (int i = 0; i < numInputs; i++) 
        {
            inputs[i] = 0;
        }
        delete [] inputs;
    }
}

//(;