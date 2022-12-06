//This code was started by Dalton Briley, on November 18, 2022
//This code was designed to create an more open source and easier understanding stepping stone to AI

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

#include "../Alpha Beam/ShapeBuilders.h"
#include "../Alpha Beam/Compute.h"

//dont forget the new[] and delete[], delete for cleaning up trash
//https://towardsdatascience.com/adventure-of-the-neurons-theory-behind-the-neural-networks-5d19c594ca16

using namespace std;


int main() {

//------------------------------------------------------------------------------------------------
	//version info and name
	string ver = "0.2.0";

	cout << "Project Alpha Beam, by Dalton Briley." << endl;
	cout << "Ver: " << ver << endl << endl;

	//open input data file
	ifstream Ginput;
	Ginput.open("input.txt");

	//Use info
	cout << "When prompted with numbers before desired inputs, enter the number." << endl << endl;
//------------------------------------------------------------------------------------------------

	int width = 0;
	int length = 0;
	int face = 0;
	int iSize = 0;
	int oSize = 0;
	int* cWidth = new int[length];
	int maxWidth = 0; //used for displaying shape check
	char answer = 'n';

//------------------------------------------------------------------------------------------------

	while (tolower(answer) == 'n') {

		//Shape input
		cout << "What shape do you intend on using?" << endl;
		cout << "1:triangle, 2:square, 3:diamond, 4:trapezoid, 5:hexagon, 6:octagon, 7:circle, 8:custom" << endl;
		int shape = 0;
		cin >> shape;
		cout << endl;
		
		cout << "\nInput Size\n";
		cin >> iSize;
		cout << "\nOutput Size\n";
		cin >> oSize;
	

			cout << "\nWidth :";
			cin >> width;
			cout << "\nLength :";
			cin >> length;

			//Triangle
			if (shape == 1) {
				face = PointCheck(face);
				//call function to build triangle nueron shape
				cWidth = BuildTriangle(width, length, face);
			}

			//Square
			if (shape == 2) {
				//call function to build square nueron shape
				cWidth = BuildSquare(width, length);
				
			}

			//Diamond
			if (shape == 3) {
				//call function to build square nueron shape
				cWidth = BuildDiamond(width, length);
			}

			//Trapezoid
			if (shape == 4) {

				cout << "\nSecondary Width: ";
				int sWidth;
				cin >> sWidth;

				face = PointCheck(face);

				//call function to build trapezoid nueron shape
				cWidth = BuildTrapezoid(width, length, sWidth, face);
				
			}

			//hexagon--
			if (shape == 5) {

			}
			
			//octagon--
			if (shape == 6) {

			}

			//circle--
			if (shape == 7) {

			}

			//Custom Shape
			if (shape == 8) {
					cout << "\nEnter the width of each layer (one at a time), starting from the input.\n";

					//call function to build custom nueron shape
					cWidth = BuildCustom(length);
			}

//------------------------------------------------------------------------------------------------
			//Shape View
			char sOut = 'n';
			cout << "\nUsing " << IarrSize(cWidth, length) << " total Nuerons with " << wbCount(cWidth, iSize, oSize, length) << " Weights and Biases";

			cout << endl << endl;
			floatCompute(cWidth, length, iSize, oSize);
			cout << endl << endl;

			cout << "\nWould you like to see your shape? (y/n): ";
			cin >> sOut;

			if (sOut == 'y') {
				OutShape(cWidth, length);
			}

			//Shape Verification
			cout << "\nWill this shape work? (y/n)";
			cin >> answer;

	}
//------------------------------------------------------------------------------------------------
	//once shape is verfied lets do some calculations





	delete[] cWidth;
	return 0;
}