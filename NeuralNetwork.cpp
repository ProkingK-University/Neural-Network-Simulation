#include <fstream>
#include <sstream>
#include <string>

#include "NeuralNetwork.h"
#include "HiddenNeuron.h"

NeuralNetwork::NeuralNetwork(std::string filePath)
{
    int numOfNeurons = 0;
    int inputLayerSize = 0;
    double* wieghtArray;
    std::string line;
    std::string data;

    std::ifstream file(filePath);

    if(!file.is_open())
    {
        std::cout<< "File failed to open" <<std::endl;
    }

    for (int i = 0; i < 2; i++)
    {
        getline(file, line);
        std::stringstream ss(line);

        for (int i = 0; i < 2; i++)
        {
            getline(ss, data, ':');
        }

        char layerType = line[0];

        if (layerType == 'i')
        {
            inputLayerSize = std::stoi(data);

            inputLayer = new InputLayer(inputLayerSize);
        }
        else if (layerType == 'n')
        {
            numHiddenLayers = std::stoi(data);
        }
    }

    hiddenLayers = new HiddenLayer*[numHiddenLayers];

    for (int i = 0; i < numHiddenLayers; i++)
    {
        getline(file, line);

        std::stringstream ss(line);
        
        for (int i = 0; i < 3; i++)
        {
            getline(ss, data, ':');
        }

        std::string activation = data;

        HiddenNeuron** neurons;

        if (activation == "relu")
        {
            std::stringstream ss(line);

            for (int i = 0; i < 2; i++)
            {
                getline(ss, data, ':');
            }
            
            numOfNeurons = std::stoi(data);
            neurons = new HiddenNeuron*[numOfNeurons];

            for (int j = 0; j < numOfNeurons; j++)
            {
                getline(file, line);
                std::stringstream ss(line);

                if (i == 0)
                {
                    wieghtArray = new double[inputLayerSize];
                    
                    for (int k = 0; k < inputLayerSize; k++)
                    {
                        getline(ss, data, ' ');

                        wieghtArray[k] = std::stod(data);
                    }
                    
                    neurons[j] = new HiddenNeuron(inputLayerSize, wieghtArray);
                }
                else
                {
                    int numOfWeights = hiddenLayers[i-1]->getNumNeurons();

                    wieghtArray = new double[numOfWeights];

                    for (int k = 0; k < numOfWeights; k++)
                    {
                        getline(ss, data, ' ');
                        
                        wieghtArray[k] = std::stod(data);
                    }
                    
                    neurons[j] = new HiddenNeuron(numOfWeights, wieghtArray);
                }
            }

            hiddenLayers[i] = new HiddenLayer(numOfNeurons, neurons, "relu");
        }
        else if (activation == "sigmoid")
        {
            std::stringstream ss(line);

            for (int i = 0; i < 2; i++)
            {
                getline(ss, data, ':');
            }
            
            numOfNeurons = std::stoi(data);
            neurons = new HiddenNeuron*[numOfNeurons];

            for (int j = 0; j < numOfNeurons; j++)
            {
                getline(file, line);
                std::stringstream ss(line);

                if (i == 0)
                {
                    wieghtArray = new double[inputLayerSize];
                    
                    for (int k = 0; k < inputLayerSize; k++)
                    {
                        getline(ss, data, ' ');
                        wieghtArray[k] = std::stod(data);
                    }
                    
                    neurons[j] = new HiddenNeuron(inputLayerSize, wieghtArray);
                }
                else
                {
                    int numOfWeights = hiddenLayers[i-1]->getNumNeurons();

                    wieghtArray = new double[numOfWeights];

                    for (int k = 0; k < numOfWeights; k++)
                    {
                        getline(ss, data, ' ');
                       
                        wieghtArray[k] = std::stod(data);
                    }
                    
                    neurons[j] = new HiddenNeuron(numOfWeights, wieghtArray);
                }
            }

            hiddenLayers[i] = new HiddenLayer(numOfNeurons, neurons, "sigmoid");
        }
    }
    
    getline(file, line);
    getline(file, line);
    std::stringstream ss(line);

    numOfNeurons = hiddenLayers[numHiddenLayers-1]->getNumNeurons();

    wieghtArray = new double[numOfNeurons];

    for (int i = 0; i < numOfNeurons; i++)
    {
        getline(ss, data, ' ');

        wieghtArray[i] = std::stod(data);
    }
    
    outputLayer = new OutputLayer(numOfNeurons, wieghtArray);

    file.close();
}

void NeuralNetwork::printNetwork()
{
    inputLayer->printLayer();

    for (int i = 0; i < numHiddenLayers; i++)
    {
        hiddenLayers[i]->printLayer();
    }

    outputLayer->printLayer();
}

void NeuralNetwork::clearNetwork()
{
    inputLayer->clearLayer();

    for (int i = 0; i < numHiddenLayers; i++)
    {
        hiddenLayers[i]->clearLayer();
    }

    outputLayer->clearLayer();
}

double NeuralNetwork::forward(double* input)
{
    inputLayer->setInputs(input);

    hiddenLayers[0]->forward(inputLayer);

    for (int i = 1; i < numHiddenLayers; i++)
    {
        hiddenLayers[i]->forward(hiddenLayers[i-1]);
    }

    outputLayer->forward(hiddenLayers[numHiddenLayers-1]);

    return outputLayer->getOutputValue();
}

NeuralNetwork::~NeuralNetwork()
{
    inputLayer = NULL;
    outputLayer = NULL;

    delete inputLayer;
    delete outputLayer;

    for (int i = 0; i < numHiddenLayers; i++) 
    {
        hiddenLayers[i] = NULL;
        delete hiddenLayers[i];
    }
    delete [] hiddenLayers;
}