#include <iostream>

using namespace std;

int main()
{
	int x;
	cout << "Enter a integer number: ";
	cin >> x;

	int y;
	cout << "Enter another integer number: ";
	cin >> y;

	if (x == y) {
		cout << "There's no sum of numbers between " << x << " and " << y << " because they're the same.\n";
		return 0;
	}

	int smaller;
	int larger;

	int sum = 0;

	if (x < y) {
		smaller = x;
		larger = y;
	}
	else {
		smaller = y;
		larger = x;
	}

	for (size_t i = smaller + 1; i < larger; i++)
		sum += i;

	cout << "The sum of all values between " << smaller << " and " << larger << " is: " << sum << ".\n";

	return 0;
}