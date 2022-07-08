#include "NeuralNetwork.h"

int main()
{
    double* input = new double[3];
    input[0] = 1.2;
    input[1] = 3.4;
    input[2] = 5.6;
    
    NeuralNetwork nn("input.txt");

    nn.printNetwork();

    double output = nn.forward(input);

    std::cout<< output <<std::endl;

    nn.clearNetwork();

    return 0;
}