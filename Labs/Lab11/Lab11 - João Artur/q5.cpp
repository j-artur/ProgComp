#include <iostream>

int main()
{
	using namespace std;

	char name[2][16] = { { '\0' }, { '\0' } };

	cout << "Insert your first and last name: ";

	for (size_t i = 0; i < 2; i++)
		cin >> name[i];

	cout << "Good morning, Mr. " <<
		name[1] << ". Or should I call you " <<
		name[0] << "?\n";

	return 0;
}
