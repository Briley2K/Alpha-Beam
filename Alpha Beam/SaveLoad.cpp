#ifndef SAVELOAD_H // include guard
#define SAVELOAD_H

#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

void SaveState(int shape/*pointers to weights and biases arrays*/) {

	ofstream Sstate;
	Sstate.open("input.txt");

	Sstate << shape << endl;
	//save state of all nuerons






}
#endif