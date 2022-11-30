//This code was written by Dalton Briley, on November 18, 2022
//This code was designed to create an more open source and easier understanding stepping stone to AI
/*
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

//dont forget the new[] and delete[], delete for cleaning up trash
//https://towardsdatascience.com/adventure-of-the-neurons-theory-behind-the-neural-networks-5d19c594ca16

using namespace std;

int main() {
	//version info and name
	string ver = "1.0.5";
	cout << "Project Alpha Beam, by Dalton Briley." << endl;
	cout << "Ver: " << ver << endl;

	//open input data file
	ifstream Ginput;
	Ginput.open("input.txt");

	//input variable function
	unsigned int inputSize = 5;  //min 1
	unsigned int nodeWith = 3;   //min 1
	unsigned int nodeLength = 5; //min 1
	unsigned int outputSize = 4; //min 1
	unsigned int resolution = 1; //min 100

	/*cout << "\nRectangle Hidden Layer layout \n";
	//Get input parameters
	cout << "\nInput Size (min 1) = ";
	cin >> inputSize;
	cout << "\nNode With (min 1) = ";
	cin >> nodeWith;
	cout << "\nNode Length (min 1) = ";
	cin >> nodeLength;
	cout << "\nNode Resolution (min 100) = "; ///doesnt do anything yet
	cin >> resolution;
	cout << "\nOutput Size (min 1) = ";
	cin >> outputSize;*/
/*
//---------------------------------------------------------------------------------------
//Weights and Inputs
//---------------------------------------------------------------------------------------
	//Inner Hidden Layer inputs
	//node gride size
	int nSize = nodeWith * nodeLength;

		int* hWeights = new int[nSize];
		int* hLayer = new int[nSize];
		int* hBias = new int[nSize];
//---------------------------------------------------------------------------------------
	//Primary layer to Hidden layer inputs

		int* pRecWeights = new int[inputSize];
		int* pLayer = new int[inputSize];
		int* pBias = new int[inputSize]; //comment out for image processing

//---------------------------------------------------------------------------------------
	//Hidden layer to Output layer inputs

		int* oRecWeights = new int[nodeWith];
		int* oLayer = new int[nodeWith];
		int* oBias = new int[nodeWith];
//---------------------------------------------------------------------------------------
//The 1st Act
//---------------------------------------------------------------------------------------

		//loading primary layer with data from Ginput text file
		int intput;
		for (int i = 0; i < inputSize; i++) {
			Ginput >> intput;
			pLayer[i] = intput;
			cout << " " << pLayer[i];
		}

		for (int i = 0; i < nSize; i++) {
			hLayer[i] = 0;
		}

		//set all weights to 1
		int x = 1, y = 1;
		for (int i = 0; i < nSize; i++) {
			hWeights[i] = x;
			hBias[i] = y;
		}

		for (int i = 0; i < outputSize; i++) {
			oRecWeights[i] = x;
			oBias[i] = y;
		}

		for (int i = 0; i < inputSize; i++) {
			pRecWeights[i] = x;
			pBias[i] = y;
		}
		
//---------------------------------------------------------------------------------------
	//Nueron Matrix Calculations	
		
		//stream data from InputLayer to first Hidden Layer

				//iterate through each hidden layer 
				for (unsigned int j = 0; j < nodeWith; j++) {
					hLayer[j] = 0;
					//iterate through each input layer
					for (unsigned int k = 0; k < inputSize; k++) {
						hLayer[j] += pRecWeights[k] * pLayer[k];
					}
					hLayer[j] += pBias[j];
				}
		//Hidden layer Calculations
			
				for (int nodeCount = 1; nodeCount < nodeLength; nodeCount++) {
				//iterate through each node starting on the 2nd layer, we already calculated for the 1st layer, aka layer 0
					for (unsigned int j = (nodeWith * nodeCount); j < (nodeWith * nodeCount) + nodeWith; j += 1) {
						hLayer[j] = 0;
						//calculate layer based on previous layer inputs
						for (unsigned int k = nodeWith * (nodeCount - 1); k < (nodeWith * nodeCount); k++) {
							hLayer[j] += hWeights[k] * hLayer[k];
						}
						hLayer[j] += hBias[j];
					}
				}
			
		//Output Layer Calculations
				for (int j = 0; j < outputSize; j += 1) {

					oLayer[j] = 0;

					for (int k = 0; k < nodeWith; k += 1) {
						oLayer[j] = hLayer[nSize - nodeWith + k] * oRecWeights[k];
					}
					oLayer[j] += oBias[j];
				}

		//test output
				cout << endl;
			for (int l = 0; l < nSize; l++) { 
				cout << hLayer[l] << " "; 
				if ((l + 1) % nodeWith == 0) {
					cout << endl;
				}
			}

//---------------------------------------------------------------------------------------	

	//back propogaion



	//Grabage Collector has come for your sweet dynamic typed variables!!!

	delete[] hWeights;
	delete[] hLayer;
	delete[] hBias;
	delete[] pRecWeights;
	delete[] pLayer;
	delete[] pBias;
	//delete[] oRecWeights;
	//delete[] oLayer;
	//delete[] oBias;

	Ginput.close();

	return 0;
}

*/