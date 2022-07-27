#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float PI = 3.14159265359;

	int angle;
	float sine;

	cout << "Insert an angle (in degrees): ";
	cin >> angle;

	sine = sin(angle * PI / 180);

	cout << "Sin of " << angle << " degrees is " << sine;
}