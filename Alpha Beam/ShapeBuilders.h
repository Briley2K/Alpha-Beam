//Visual Shape Builders (Main() Cleanup)
#pragma once


int PointCheck(int face);

//Cout shape
void OutShape(int* cWidth, int length);

//build custom shape in cWidth
int* BuildCustom(int length);

//build traingle shape in cWidth
int* BuildTriangle(int width, int length, int face);

//build square shape in cWidth
int* BuildSquare(int width, int length);

//build diamond shape in cWidth
int* BuildDiamond(int width, int length);

//build trapezoid shape in cWidth
int* BuildTrapezoid(int width, int length, int sWidth, int face);
