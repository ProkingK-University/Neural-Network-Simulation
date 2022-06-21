#ifndef OUTER_LAYER_H
#define OUTER_LAYER_H

#include "HiddenLayer.h"

class OutputLayer
{
private:
    int numWeights;

    double* weights;
    double outputValue;
public:
    OutputLayer(int numWeights, double* weights);

    void printLayer();
    void clearLayer();
    void setsOutputValue(double outputValue);
    void forward(HiddenLayer* lastHiddenLayer);

    double getOutputValue();

    ~OutputLayer();
};

#endif