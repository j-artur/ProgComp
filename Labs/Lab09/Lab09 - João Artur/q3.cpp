#include <iostream>

int main()
{
	using namespace std;

	double number;
	cout << "Insert a real number: ";
	cin >> number;

	int integer = number;
	double part = number - integer;

	cout << "The integer part: " << integer << '\n';
	cout << "The fractionary part: " << part << '\n';
}