#include <iostream>

using namespace std;

int main()
{
	int size = 0;
	cout << "How many integers do you want to store? ";
	cin >> size;

	int* arr = new int[size];

	cout << "What are the values? ";
	for (size_t i = 0; i < size; i++)
		cin >> arr[i];

	cout << "Values ";
	for (size_t i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i];
		else if (i == size - 2)
			cout << arr[i] << " and ";
		else
			cout << arr[i] << ", ";
	}
	cout << " were stored.";

	delete[] arr;

	return 0;
}
