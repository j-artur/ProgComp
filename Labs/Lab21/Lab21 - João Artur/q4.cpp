#include <iostream>

using namespace std;

int main()
{
	unsigned long long last = 0;
	unsigned long long curr = 1;

	unsigned long long sum = 0;

	cout << "Sequence:\n";
	for (unsigned long long next = curr; next < 4000000; next = curr + last) {
		last = curr;
		curr = next;

		cout << curr << '\n';

		if (!(curr % 2)) sum += curr;
	}

	cout << "\nSum of even: " << sum << '\n';

	return 0;
}
