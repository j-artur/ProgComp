#include <iostream>

using namespace std;

int main()
{
	int matrix[4][4] =
	{
		{ 3, 1, 5, 5 },
		{ 1, 5, 5, 6 },
		{ 2, 3, 4, 5 },
		{ 4, 9, 1, 8 }
	};

	int sums[4] = { 0, 0, 0, 0 };

	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 4; j++)
			sums[i] += matrix[j][i];

	cout << "The sums of the columns are:";
	for (int sum : sums)
		cout << ' ' << sum;
	cout << '\n';

	return 0;
}
