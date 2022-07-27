#include <iostream>

using namespace std;

int main()
{
	int length;
	cout << "You want me to count from 1 to what number? ";
	cin >> length;

	int* arr = new int[length];
	for (size_t i = 0; i < length; i++)
		arr[i] = int(i + 1);


	for (int i = 0; i < length; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	for (int i = length - 1; i > -1; i--)
		cout << arr[i] << ' ';
	cout << '\n';

	for (int i = 0; i < length; i++)
		if (arr[i] % 2)
			cout << arr[i] << ' ';
	cout << '\n';

	for (int i = length - 1; i > -1; i--)
		if (arr[i] % 2)
			cout << arr[i] << ' ';
	cout << '\n';

	for (int i = 0; i < length; i++)
		if (arr[i] % 2 == 0)
			cout << arr[i] << ' ';
	cout << '\n';

	for (int i = length - 1; i > -1; i--)
		if (arr[i] % 2 == 0)
			cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}
