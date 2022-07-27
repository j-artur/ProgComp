#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int Px, Py, Qx, Qy;
	float sideA, sideB, distance;

	cout << "Point P:\n";
	cin >> Px >> Py; 
	cout << "Point Q:\n";
	cin >> Qx >> Qy;

	sideA = Qx - Px;
	sideB = Qy - Py;

	distance = sqrt(pow(sideA, 2) + pow(sideB, 2));

	cout << "\nThe distance between P and Q is: " << distance;
}