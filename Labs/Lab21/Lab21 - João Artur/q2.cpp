#include <iostream>

using namespace std;

int main()
{
	unsigned number;
	cout << "Enter a integer+ number: ";
	cin >> number;

	try {
		for (int i = 2; i < number; i++)
			if (number % i == 0)
				throw i;

		cout << "Prime.\n";
	}
	catch (const int i) {
		cout << "Not prime, divisible by " << i << ".\n";
	}

	return 0;
}
