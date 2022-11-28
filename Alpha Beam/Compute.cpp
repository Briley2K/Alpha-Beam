//take input and propogate through the nueral net

#include <array>
#include <iostream>

using namespace std;

//return the amount of nuerons described by cWidth
int* NetSize(int* cWidth) { // probelms

	int* size = 0;

	for (int i = 0; i < sizeof(cWidth); i++) {
		size += cWidth[i];
		cout << cWidth[i];
	}
	return size;
}
/*
void* Compute(int* cWidth, int length) {



	//nural net matrix
	int* net = new int[length];
	int* input = new int[length];
	int* weghts = new int[length];
	int* biases = new int[length];



}*/