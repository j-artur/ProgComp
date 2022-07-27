#include <iostream>
#include <cmath>
using namespace std;

float square(float);
float cube(float);

int main()
{
	float value;

	cout << "Insert a value: ";
	cin >> value;

	cout << "\nSquare: " << square(value);
	cout << "\nCube: " << cube(value);
	cout << "\nCubed square: " << cube(square(value));
}

float square(float number)
{
	return pow(number, 2);
}

float cube(float number)
{
	return pow(number, 3);
}