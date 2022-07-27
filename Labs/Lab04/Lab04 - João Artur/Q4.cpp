#include <iostream>
#include <cmath>
using namespace std;

float cylinderVolume(float, float);

int main()
{
	
	float height, radius;

	cout << "Calculate the volume of a cylinder\n";
	cout << "----------------------------------\n";
	cout << "Insert the radius of the base: ";
	cin >> radius;
	cout << "Insert the height: ";
	cin >> height;

	cout << "The volume of the cylinder is " << cylinderVolume(height, radius);
}

float cylinderVolume(float height, float radius)
{
	float PI = 3.14159;

	float area = PI * pow(radius, 2);
	float volume = area * height;

	return volume;
}