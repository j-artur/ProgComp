#include <iostream>

void displayVector(int[]);

int main()
{
	using namespace std;

	int vector[5] = { 10, 80, 30, 45, 15 };

	const string SEPARATOR = "----------------------\n";

	displayVector(vector);

	cout << SEPARATOR;

	unsigned short pos;
	cout << "Change position: ";
	cin >> pos;

	int value;
	cout << "New value: ";
	cin >> value;

	cout << SEPARATOR;

	vector[pos] = value;

	displayVector(vector);

	return 0;
}

void displayVector(int arr[])
{
	std::cout << "Vector:";
	for (size_t i = 0; i < 5; i++)
		std::cout << ' ' << arr[i];
	std::cout << '\n';
}