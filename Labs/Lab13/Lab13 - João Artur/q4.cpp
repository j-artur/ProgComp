#include <iostream>

enum day { SUN, MON, TUE, WED, THU, FRI, SAT };

int main()
{
	using namespace std;

	char days[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	for (day i = SUN; i <= SAT; i = day(i + 1))
		cout << days[i] << '\n';

	return 0;
}
