//Compute functions for nueral net
#pragma once

//return the total of all elements in the array
int IarrSize(int* arr, int size);
float FarrSize(float* arr, float size);

//Open input file and stream in data (cycle through different chunks fo data with Iterator)
void fileRead(int* Input, int iSize, int iter);

//returns the amount of weights and biases needed
int wbCount(int* cWidth, int iSize, int oSize, int length);

//Zero a float array
void valFArray(float* arr, float size, float val);

//Zero an int array
void valIArray(int* arr, int size, int val);

void floatCompute(int* cWidth, int length, int iSize, int oSize);