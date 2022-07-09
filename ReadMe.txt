What it is:

This program is a simulation of a Neural Network. 
It consists of 3 layers, the hidden neuron and the actual Neural Network. 
The 3 layers are the input layer, hidden layer and output layer.
All of these layers are are classes including the hidden neuron and the Neural Network.

How it works:

Input layer - takes in an array of doubles as the input of the Neural Network.
Hidden layer - moves values from the input layer to the output layer and performes calculations depending on the parameters given.
Output layer - returns the final value of the Neural Network.

Format for "input.txt":

******************************************************************************************************************
i:3                     <<< Input layer size 3

num_hidden_layers:3     <<< Neural Network will have 3 hidden layers

h:5:relu                <<< Fist hidden layer will have 5 neurons with ReLU activation

0.1 0.2 0.3             =
1.1 1.2 1.3             =
2.1 2.2 2.3             = <<< 5 rows equal 5 neurons and 3 colunms equal number of wieghts per neuron
3.1 3.2 3.3             =
4.1 4.2 4.3             =

h:2:sigmoid             <<< Fist hidden layer will have 2 neurons with Sigmoid activation

5.1 5.2 5.3 5.4 5.5
6.1 6.2 6.3 6.4 6.5

h:3:relu

7.1 7.2
8.3 8.4
9.5 9.6

o:1                     <<< Output layer always has 1 neuron

10.1 10.2 10.3

******************************************************************************************************************

Note:

-Follow format strictly
-For activation only "relu" or "sigmoid" allowed
-Example of format is in "input.txt"

END ;)