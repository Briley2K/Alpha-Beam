//Compute functions for nueral net
#pragma once

//return the amount of nuerons described by cWidth
int NetSize(int* cWidth, int length);

//Open input file and stream in data (cycle through different chunks fo data with Iterator)
void fileRead(int* Input, int length, int iterator);

//Zero a float array
void zeroFArray(float* arr, int size);

//Zero an int array
void zeroIArray(int* arr, int size);

void floatCompute(int* cWidth, int length, int iSize, int oSize);
