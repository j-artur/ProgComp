#include <iostream>

using namespace std;

bool isDivisibleBy(int, int);

int main() {
	int number = 2;

	while (!isDivisibleBy(number, 20))
		number++;

	cout << number;

	return 0;
}

bool isDivisibleBy(int number, int max) {
	for (size_t i = 1; i <= max; i++)
		if (number % i)
			return false;

	return true;
}
