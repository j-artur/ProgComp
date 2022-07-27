#include <iostream>

using namespace std;

void showArray(short*, size_t);

int main()
{
	cout << "Insert 10 values: ";

	short arr[10];
	for (size_t i = 0; i < 10; i++)
		cin >> arr[i];

	short matrix[3][5];

	for (size_t i = 0; i < 5; i++)
	{
		matrix[0][i] = arr[i];
		matrix[1][i] = arr[i + 5];
		matrix[2][i] = arr[i] + arr[i + 5];
	}

	cout << "Array A: "; showArray(matrix[0], 5);
	cout << "Array B: "; showArray(matrix[1], 5);
	cout << "Array S: "; showArray(matrix[2], 5);

	return 0;
}

void showArray(short* arr, size_t len)
{
	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';

	std::cout << '\n';
}