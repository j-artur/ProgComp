#include <iostream>

using namespace std;

void printInts(int*, size_t);

int main()
{
	int mat[2][3] =
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	int testArray[] = { 1, 2, 3 };

	printInts(mat[0], 3);

	printInts(testArray, 3);

	return 0;
}

void printInts(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}
