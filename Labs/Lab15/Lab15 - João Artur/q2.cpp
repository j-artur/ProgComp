#include <iostream>

using namespace std;

int main()
{
	int* value = new int{ 100 };

	cout << "Stored content: " << *value;

	cout << "\nInsert a new value for that block of memory: ";
	cin >> *value;

	cout << "Stored content: " << *value;

	delete value;

	return 0;
}
