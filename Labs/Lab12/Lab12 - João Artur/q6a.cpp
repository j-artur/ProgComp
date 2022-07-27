#include <iostream>
#include "q6a.h"

int main()
{
	using namespace std;

	cout << "Begin: ";
	Time begin = newTime();
	cout << "End: ";
	Time end = newTime();

	Time between = subtractTime(begin, end);

	cout << '\n';
	cout << "Between ";
	showTime(begin, 0);
	cout << " and ";
	showTime(end, 0);
	cout << " there are ";
	showTime(between, 1);
	cout << ", that means, ";
	showTime(between, 2);
	cout << ".\n";

	return 0;
}
