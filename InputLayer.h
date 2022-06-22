#ifndef INPUT_LAYER_H
#define INPUT_LAYER_H

class InputLayer
{
private:
    int numInputs;
    double* inputs;
public:
    InputLayer(int numInputs);

    void printLayer();
    void clearLayer();
    void setInputs(double* inputs);
    void setNumInputs(int numInputs);

    int getNumberInputs();
    double* getInputs();

    ~InputLayer();
};

#endif