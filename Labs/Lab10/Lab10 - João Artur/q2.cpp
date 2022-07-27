#include <iostream>

int main()
{
	using namespace std;

	float weights[3] = { 2, 3, 4 };
	float grades[3];

	cout << "Insert three grades: ";
	for (size_t i = 0; i < 3; i++)
		cin >> grades[i];

	float oldAverage = 0;
	float newAverage = 0;
	for (size_t i = 0; i < 3; i++)
	{
		oldAverage += grades[i] * weights[i] / 9;
		newAverage += grades[i] / 3;
	}

	cout << "The average grade on the old system is: " << oldAverage << '\n';
	cout << "The average grade on the new system is: " << newAverage << '\n';

	return 0;
}