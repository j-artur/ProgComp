#include <iostream>

double calculate(double, double, double);

int main()
{
	using namespace std;

	double arr[3];

	cout << "Insert three values into the array: ";
	for (size_t i = 0; i < 3; i++)
		cin >> arr[i];

	cout << "The result is: " << calculate(arr[0], arr[1], arr[2]);

	return 0;
}

double calculate(double first, double second, double third)
{
	return first * third - second;
}