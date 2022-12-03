//take input and propogate through the nueral net

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//return the total of all elements in the array
int INetSize(int *arr) {

	int count = 0;
	int iter = 0;
		while (arr[iter] > 0) {

			count += arr[iter];
			iter++;
		}
		return count;
}

float FNetSize(float* arr) {

	float count = 0;
	int iter = 0;
	while (arr[iter] > 0) {

		count += arr[iter];
		iter++;
	}
	return count;
}

//Open input file and stream in data (cycle through different chunks fo data with Iterator)
void fileRead(int* Input, int iSize, int iter) {


	//open input file
	ifstream finput;
	finput.open("input.txt");

	//Stream data from finput to Input array
	for (int i = iSize * iter; i < (iSize * iter) + iSize; i++) {
		 finput >> Input[i];
	}
}

//returns the amount of weights and biases needed
int wbCount(int* cWidth,int iSize, int oSize, int length) {
	int wSize = 0;
	wSize += cWidth[0] * iSize;

	for (int i = 1; i < length; i++) {
		wSize += cWidth[i] * cWidth[i - 1];
	}
	wSize += cWidth[length - 1] * oSize;

	return wSize;
}

//Zero an float array
void zeroFArray(float *arr) {

	float size = FNetSize(arr);

	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

//Zero an int array
void zeroIArray(int* arr) {

	int size = INetSize(arr);

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
	int size = INetSize(cWidth);
	//weights and biases size
	int wbSize = wbCount(cWidth, iSize, oSize, length);

//------------------------------------------------------------------------------------------------

	//nural net matrix
	float* net = new float[size];

	float* weights = new float[wbSize];
	float* biases = new float[size];

	float* input = new float[iSize];
	float* output = new float[oSize];
//------------------------------------------------------------------------------------------------
	  
	//set all float arrays to 0
	zeroFArray(net);

	zeroFArray(weights);
	zeroFArray(biases);

	zeroFArray(input);
	zeroFArray(output);

//------------------------------------------------------------------------------------------------
	//calculate input weights and biases on 1st nueron layer


	for (int i = 0; i < cWidth[0]; i ++) {//iterate though each nueron on the first layer i=thenueron

		for (int j = 0; j < iSize; i++) {//iterate through each weight and input
			net[i] += input[(i*iSize)+j] * weights[(i*iSize)+j];
		}
		net[i] += biases[i];
	}

	//Calulate rest of nueron layer
	int count = 0;
	for (int i = 1; i < length; i++) { //layer interation starting on second layer
		count += cWidth[i - 1];

		for (int j = count; j < cWidth[i] + count; j++) {//interate through each nureon on the layer that needs calc

			for (int k = count - cWidth[i - 1]; k < count; k++) {//iterate through each nueron on the previous layer

				net[j] += net[k] * weights[k];

			}
			net[j] += biases[j];
		}
		
	}

	
	//Calculate output layer

}