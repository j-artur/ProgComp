#include <iostream>
#include <cmath>
using namespace std;

int absoluteValue(int);

int main()
{
	float integer;

	cout << "Insert a integer: ";
	cin >> integer;
	cout << "Its absolute value is " << absoluteValue(integer) << ".";
}

/*
int absoluteValue(int number)
{
	return (number < 0 ? -number : number);
}
*/

int absoluteValue(int number)
{
	float abs = sqrt(
		pow(number, 2)
	);
	return abs;
}