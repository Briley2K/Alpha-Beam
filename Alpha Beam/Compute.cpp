//take input and propogate through the nueral net

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//return the total of all elements in the array
int IarrSize(int *arr, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		count += *(&arr[i]);
	}
		return count;
}
float FarrSize(float* arr, float size) {

	float count = 0;
	for (int i = 0; i < size; i++) {
		count += *(&arr[i]);
	}

	return count;
}

//Open input file and stream in data (cycle through different chunks of data with Iterator)
//will implement a more robust file reader in the future.
void fileRead(float* Input, string filename, int iSize, int iter) {

	//open input file
	ifstream finput;
	finput.open(filename);

	//Stream data from finput to Input array
	for (int i = iSize * iter; i < (iSize * iter) + iSize; i++) {
		 finput >> Input[i];
	}
}

//returns the amount of weights and biases needed
int wbCount(int* cWidth,int iSize, int oSize, int length) {
	int wSize = 0;
	
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			wSize += cWidth[i] * iSize;
		}
		if (i > 0) {
			wSize += cWidth[i] * cWidth[i - 1];
		}
	}

	wSize += cWidth[length - 1] * oSize;
	return wSize;
}

//set an float array to val
void valFArray(float *arr, float size, float val) {

	for (int i = 0; i < size; i++) {
		*(&arr[i]) = val;
	}
}
//int
void valIArray(int* arr, int size, int val) {

	for (int i = 0; i < size; i++) {
		*(&arr[i]) = val;
	}
}

//calculate output of nueral net
void calcOutput(int* cWidth, float* net, float* biases, float* weights, float* input, float* output, int length, int iSize, int oSize, int size, int wbSize) {

//------------------------------------------------------------------------------------------------
	//Input to Shape 
		//calculate input weights and biases on 1st nueron layer
	for (int i = 0; i < cWidth[0]; i++) {//iterate though each nueron on the first layer i=thenueron
		for (int j = 0; j < iSize; j++) {//iterate through each weight and input
			net[i] += input[j] * weights[(i * iSize) + j];
		}
		net[i] += biases[i];
	}

//------------------------------------------------------------------------------------------------
	//Shape Calc
	//Calulate rest of nueron layer
	int count = 0;
	//iterate through each weight starting on the weights on the second row
	int countTwo = iSize * cWidth[0];

	for (int i = 1; i < length; i++) { //layer interation starting on second layer
		count += cWidth[i - 1];
		for (int j = count; j < cWidth[i] + count; j++) {//interate through each nureon on the layer that needs calc
			for (int k = count - cWidth[i - 1]; k < count; k++) {//iterate through each nueron on the previous layer 
				*(&net[j]) += *(&net[k]) * *(&weights[countTwo]);
				countTwo++;
			}
			*(&net[j]) += *(&biases[j]);
		}
	}

//------------------------------------------------------------------------------------------------
	//Shape to Output
	for (int i = 0; i < oSize; i++) {//iterate though each nueron on the output layer i=thenueron
		for (int j = size - cWidth[length - 1]; j < size; j++) {//iterate through each weight and input
			*(&output[i]) += *(&net[j]) * *(&weights[countTwo]);
			countTwo++;
		}
	}

}

//sigmoid activation
float SigmoidAct(float* output, int index) {
	float result = 1 / (1 + exp(-output[index]));
	return result;
}

//does exactly what you think it does
void deleteArrays(float* net, float* biases, float* weights, float* input, float* output) {
	delete[] net;
	delete[] biases;
	delete[] weights;
	delete[] input;
	delete[] output;
}

//create and propogate and learn, the meat
void NetSolve(int* cWidth, int length, int iSize, int oSize) {


	//set size to amount of total nuerons
	int size = IarrSize(cWidth, length);

	//weights and biases size
	int wbSize = wbCount(cWidth, iSize, oSize, length);
//------------------------------------------------------------------------------------------------

		//Nueral net arrays creation
	float* net = new float[size];
	float* biases = new float[size];
	float* weights = new float[wbSize];
	float* input = new float[iSize];
	float* output = new float[oSize];
	float* testoutput = new float[oSize];

//------------------------------------------------------------------------------------------------
//pre calc Set-Up
	char answer = 'n';
	cout << "\nWould you like to set the starting Weights, Biases, Nueron values?(recommended)(y/n): ";
	cin >> answer;
	//set all float arrays to a value (recommended)
	if (tolower(answer) == 'y') {
		float value;
		cout << "\n Nuerons = ";
		cin >> value;
		valFArray(net, size, value);
		cout << "\n Weights = ";
		cin >> value;
		valFArray(weights, wbSize, value);
		cout << "\n Biases = ";
		cin >> value;
		valFArray(biases, size, value);

		//input and outputs will default to 0
		valFArray(input, iSize, 0);
		valFArray(output, oSize, 0);
	}

	//read input values from file into an array for parsing into input array
	string infilename;
	cout << "\nWhat is the name of the Input File?: ";
	cin >> infilename;
	fileRead(input, infilename, iSize, 0);

	string outfilename;
	cout << "\nWhat is the name of the Test File?: ";
	cin >> outfilename;
	fileRead(testoutput, outfilename, iSize, 0);

	

//------------------------------------------------------------------------------------------------
	// calc output
	// train
	//------------------------------------------------------------------------------------------------


	
	deleteArrays(net, biases, weights, input, output);
}

