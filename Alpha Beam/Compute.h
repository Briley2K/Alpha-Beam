//Compute functions for nueral net
#pragma once

//return the amount of nuerons described by cWidth
int NetSize(int* arr);
float FNetSize(float* arr);

//Open input file and stream in data (cycle through different chunks fo data with Iterator)
void fileRead(int* Input, int iSize);

//returns the amount of weights and biases needed
int wbCount(int* cWidth, int iSize, int oSize, int length);

//Zero a float array
void zeroFArray(float* arr);

//Zero an int array
void zeroIArray(int* arr);

void floatCompute(int* cWidth, int length, int iSize, int oSize);
