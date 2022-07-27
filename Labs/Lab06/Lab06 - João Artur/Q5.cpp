#include <iostream>
#include <climits>
using namespace std;

bool isShort(long long);
bool isInt(long long);

int main()
{
	cout << "Insert a integer value: ";
	long long number;
	cin >> number;

	cout << '\n';

	cout << number << (isShort(number) ? " fits" : " doesn't fit") << " in " << sizeof(short) * 8 << " bits\n";
	cout << number << (isInt(number) ? " fits" : " doesn't fit") << " in " << sizeof(int) * 8 << " bits\n";
}

bool isShort(long long number)
{
	if (number < SHRT_MIN || number > SHRT_MAX) 
		return false;

	return true;
}

bool isInt(long long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return false;

	return true;
}
