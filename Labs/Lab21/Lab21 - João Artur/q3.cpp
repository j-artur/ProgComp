#include <iostream>

using namespace std;

int main()
{
	unsigned sum = 0;

	for (unsigned i = 0; i < 1000; i++)
		if (i % 5 == 0 || i % 3 == 0)
			sum += i;

	cout << "Sum: " << sum << '\n';

	return 0;
}
