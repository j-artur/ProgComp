#include <iostream>
#include <cmath>
using namespace std;

float BMI(float, float);

int main()
{
	float height, weight;

	cout << "Body Mass Index (BMI)\n";
	cout << "---------------------\n";
	cout << "Height: ";
	cin >> height;
	cout << "Weight: ";
	cin >> weight;

	cout << "BMI: " << BMI(weight, height) << endl;
}

float BMI(float weight, float height)
{
	return weight / pow(height, 2);
}