#include <iostream>

struct Time
{
	unsigned short hour = 0;
	unsigned short minute = 0;
	unsigned short second = 0;
};

int main()
{
	using namespace std;

	Time begin;
	cout << "Begin: ";
	cin >> begin.hour;
	cin.ignore(1);
	cin >> begin.minute;

	Time end;
	cout << "End: ";
	cin >> end.hour;
	cin.ignore(1);
	cin >> end.minute;

	Time between;

	int betweenMinutes = (end.hour * 60 + end.minute) - (begin.hour * 60 + begin.minute);
	between.hour = betweenMinutes / 60;
	between.minute = betweenMinutes % 60;

	cout << '\n' <<
		"Between " << begin.hour << ':' << begin.minute <<
		" and " << end.hour << ':' << end.minute <<
		" there are " << betweenMinutes << " minutes," <<
		" that means, " << between.hour << "h and " << between.minute << "min" <<
		".\n";

	return 0;
}
