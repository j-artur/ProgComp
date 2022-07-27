#include <iostream>
#include "Q6.h"
using namespace std;

int main()
{
	float x, y;

	cout << "Insert the coordinates of the vector:\n";
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;

	cout << "Polar coordinates of the vector:\n";
	cout << '(' << norm(x, y) << ", " << angle(x, y) << ')' << endl;
}