//take input and propogate through the nueral net

#include <iostream>
#include <fstream>
#include <vector>

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

//cWidth = the nureon layout array
//length = the amount of layers in nueron grid
//Isize = Input size
//Osize = Output size

void floatCompute(int* cWidth, int length, int iSize, int oSize) {
	

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

//------------------------------------------------------------------------------------------------

	//set all float arrays to a value
	valFArray(net, size, 1);
	valFArray(weights, wbSize, 1);
	valFArray(biases, size, 1);
	valFArray(input, iSize, 1);
	valFArray(output, oSize, 0);

//------------------------------------------------------------------------------------------------
 
//Input to Shape 
	//calculate input weights and biases on 1st nueron layer
	for (int i = 0; i < cWidth[0]; i ++) {//iterate though each nueron on the first layer i=thenueron

		cout << endl << "input calc nueron = " << i;//test

		for (int j = 0; j < iSize; j++) {//iterate through each weight and input
			net[i] += input[j] * weights[(i*iSize)+j];

			cout << endl << "input previous nueron = " << j << " weight: " << (i * iSize) + j;//test

		}
		net[i] += biases[i];
	}

//Shape Calc

	//Calulate rest of nueron layer
	int count = 0;
	//iterate through each weight starting on the weights on the second row
	int countTwo = iSize * cWidth[0]; 


	for (int i = 1; i < length; i++) { //layer interation starting on second layer
		count += cWidth[i - 1];
		
		cout << endl << "i layer = " << i;//test

		for (int j = count; j < cWidth[i] + count; j++) {//interate through each nureon on the layer that needs calc 11,12,13,14       count = 11          i=2

			cout << endl << "j calc nueron = " << j;//test

			for (int k = count - cWidth[i - 1]; k < count; k++) {//iterate through each nueron on the previous layer 6,7,8,9,10        cWidth[i-1] = 5    need 60 from this

				cout << endl << "k previous nueron = " << k << " Weight: " << (countTwo) << "|" << count << "|" << countTwo << " This N=" << j;//test

					*(&net[j]) += *(&net[k]) * *(&weights[countTwo]);

					countTwo++;	
			}
			*(&net[j]) += *(&biases[j]);
		}
	}

//Shape to Output
	for (int i = 0; i < oSize; i++) {//iterate though each nueron on the output layer i=thenueron

		cout << endl << "out nureon = " << i ;

		for (int j = size - cWidth[length - 1]; j < size; j++) {//iterate through each weight and input

			cout << endl << "previous nueron = " << j << " Weight: " << countTwo << " this N = o" << i;

			*(&output[i]) += *(&net[j]) * *(&weights[countTwo]);
			countTwo++;
		}
	}



//------------------------------------------------------------------------------------------------	
	//Calculate output layer


	delete[] net;
	delete[] biases;

	delete[] weights;

	delete[] input;
	delete[] output;
	//tests

}

//Test Code
/*
	cout << endl << "Net:";
	for (int i = 0; i < size; i++) {
		cout << "|" << *(&net[i]);

	}
	cout << endl << "Weights:";
	for (int i = 0; i < wbSize; i++) {
		cout << "|" << *(&weights[i]);

	}
	cout << endl << "Biases:";
	for (int i = 0; i < size; i++) {
		cout << "|" << *(&biases[i]);

	}
	cout << endl << "Input:";
	for (int i = 0; i < iSize; i++) {
		cout << "|" << *(&input[i]);

	}
	cout << endl << "Output:";
	for (int i = 0; i < oSize; i++) {
		cout << "|" << *(&output[i]);

	}
	cout << endl;
	cout << endl;



*/