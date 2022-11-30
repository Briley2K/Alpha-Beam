//take input and propogate through the nueral net

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//return the amount of nuerons described by cWidth
int NetSize(int *cWidth, int length) { // probems

	int size = 0;
	for (int i = 0; i < length; i++) {
		size += cWidth[i];
	}
	return size;
}

//Open input file and stream in data (cycle through different chunks fo data with Iterator)
//first chuck of data falls under iterator 0.
void fileRead(int* Input, int length, int iterator) {

	//open input file
	ifstream finput;
	finput.open("input.txt");

	//Stream data from finput to Input array
	for (int i = iterator; i < length; i++) {
		 finput >> Input[i];
	}
	
}

//Zero an float array
void zeroFArray(float *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

//Zero an int array
void zeroIArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

//cWidth = the nureon layout array
//length = the amount of layers in nueron grid
//Isize = Input size
//Osize = Output size
void floatCompute(int* cWidth, int length, int iSize, int oSize) {//needs and int variant after completion that relies on int operations for speed
	
	//set size to amount of total nuerons
	int size = NetSize(cWidth, length);

	//nural net matrix
	float* net = new float[size];

	float* weights = new float[size + iSize + oSize];
	float* biases = new float[size + iSize + oSize];

	float* input = new float[iSize];
	float* output = new float[oSize];
//------------------------------------------------------------------------------------------------
	//set all arrays to 0
	zeroFArray(net, size);
	zeroFArray(weights, size + iSize + oSize);
	zeroFArray(biases, size + iSize + oSize);
	zeroFArray(input, iSize);
	zeroFArray(output, oSize);

//------------------------------------------------------------------------------------------------
	//calculate input weights and biases on 1st nueron layer
	for (int i = 0; i < cWidth[0]; i ++) {

		for (int j = 0; j < iSize; i++) {
			net[i] += input[j] * weights[j];
		}
		net[i] += biases[i];
	}
	int count = 0;
	//Calulate rest of nueron layer
	for (int i = 1; i < length; i++) { //layer interation starting on second layer
		count += cWidth[i - 1];

		for (int j = 0; j <= cWidth[i - 1]; j++) {//interate through each nureon on the layer that needs calc

			net[count + j] = net[count - cWidth[i] + j] * weights[count - cWidth[i] + j];

		}
		net[i] += biases[i];
	}

	//Calculate output layer


}