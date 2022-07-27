#include <iostream>

using namespace std;

int accumulate(int, int);

int main()
{
	int n[2];
	cout << "Insert the start and the end of the interval: ";
	for (size_t i = 0; i < 2; i++)
		cin >> n[i];

	cout << accumulate(n[0], n[1]);

	return 0;
}

int accumulate(int start, int end)
{
	int acc = 0;

	for (int i = start; i < end + 1; i++)
		acc += i;

	return acc;
}