#include <iostream>
#include <cmath>
using namespace std;

float norm(float, float);

int main()
{
	float x, y;

	cout << "Insert the coordinates of the vector:\n";
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;

	cout << "The norm of the vector is " << norm(x, y) << endl;
}

float norm(float x, float y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}