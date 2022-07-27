#include <iostream>

using namespace std;

int main()
{
	short arr[] = { 32, 16, 47, 10, 82, 29, 30, 28, 15, 64 };

	for (size_t i = 0; i < 5; i++)
		cout << '[' << arr[i] << ',' << arr[9 - i] << "] ";

	return 0;
}
