#include <iostream>
#include <cmath>
using namespace std;

float angle(float, float);

int main()
{
	float x, y;

	cout << "Insert the coordinates of the vector:\n";
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;

	cout << "The angle of the vector is " << angle(x, y) << " degrees." << endl;
}

float angle(float x, float y)
{
	float PI = 3.14159265359;

	float radAngle = atan2(y, x);
	float degAngle = radAngle * 180 / PI;

	return degAngle;
}