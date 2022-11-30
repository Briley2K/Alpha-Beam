//Visual Shape Builders (Main() Cleanup)

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//output shape to screen

//get which way the shape is supposed to point
int PointCheck(int face) {

	cout << "\nInput meets (1:Face, 2:Point): ";
	cin >> face;

	return face;
}

//Cout shape
void OutShape(int* cWidth, int length) {

	//get max width of the shape
	int maxWidth = 0;
	for (int i = 0; i < length; i++) {
		if (maxWidth < cWidth[i]) {
			maxWidth = cWidth[i];
		}
	}
	//build shape of layers
	cout << "INPUT" << endl;
	for (int i = 0; i < length; i++) {

		for (int j = 0; j < (maxWidth / 2) - (cWidth[i] / 2); j++) {
			cout << ' ';
		}

		for (int k = 0; k < cWidth[i]; k++) {
			cout << '*';
		}

		cout << endl;
	}
}

//build custom shape in cWidth
int* BuildCustom(int length) {

	int* cWidth = new int[length];

	for (int i = 0; i < length; i++) {
		cin >> cWidth[i];

	}
	return cWidth;
	delete[] cWidth;
}

//build traingle shape in cWidth
int* BuildTriangle(int width, int length, int face) {

	int* cWidth = new int[length];

	if (face == 1) { //Face to Input

		int j = length;
		for (int i = 1; i <= length; i++) {
			cWidth[i - 1] = (width / length) * j;
			j--;
		}
	}

	if (face == 2) { //Point to Input
		for (int i = 1; i <= length; i++) {
			cWidth[i - 1] = (width / length) * i;
		}

	}
	return cWidth;
	delete[] cWidth;
}

//build square shape in cWidth
int* BuildSquare(int width, int length) {

	int* cWidth = new int[length];

	for (int i = 0; i < length; i++) {
		cWidth[i] = width;
	}


	return cWidth;
	delete[] cWidth;
}

//build diamond shape in cWidth
int* BuildDiamond(int width, int length) {

	int* cWidth = new int[length];
	int hlength = length / 2;

	for (int i = 1; i <= hlength + 1; i++) {
		cWidth[i - 1] = (width / hlength) * i;
	}

	int j = hlength;
	for (int i = hlength; i <= length; i++) {
		cWidth[i - 1] = (width / hlength) * j;//fix
		j--;
	}

	return cWidth;
	delete[] cWidth;
}

//build trapezoid shape in cWidth
int* BuildTrapezoid(int width, int length, int sWidth, int face) { // needs adjusting
	int* cWidth = new int[length];

	//cWidth[i - 1] = width - length / sWidth
	float w = width;
	float sW = sWidth;
	float l = length;

	if (face == 1) { //Face to Input

		for (int i = 1; i <= length; i++) {
			cWidth[i - 1] = width - round((((w - sW) / l) * i));
			cout << width - round((((w - sW) / l) * i)) << " ";

		}
	}

	if (face == 2) { //Point to Input
		int j = length;
		for (int i = 1; i <= length; i++) {
			cWidth[i - 1] = width - round((((w - sW) / l) * j));
			cout << width - round((((w - sW) / l) * j)) << " ";
			j--;

		}
	}


	return cWidth;
	delete[] cWidth;
}