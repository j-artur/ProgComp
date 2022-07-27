#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string name;
	string date;

	cout << "Insert your name: ";
	getline(cin, name);
	cout << "Insert the date: ";
	getline(cin, date);

	cout << name + " was here on " + date + '.';

	return 0;
}
