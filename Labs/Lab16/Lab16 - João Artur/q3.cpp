#include <iostream>

using namespace std;

int main()
{
	short arr[] = { 46, 78, 40, 96, 74, 58, 32, 56, 91, 6 };

	short* group[2] = { &arr[0], &arr[1] };

	for (size_t i = 0; i < 10; i += 2)
		cout << '[' << group[0][i] << ',' << group[1][i] << "] ";

	delete[] group;

	return 0;
}
