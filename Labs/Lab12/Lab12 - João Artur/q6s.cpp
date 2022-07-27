#include <iostream>
#include "q6a.h"

using namespace std;

Time newTime()
{
	Time time;

	cin >> time.hour;
	cin.ignore(1);
	cin >> time.minute;

	return time;
}

void showTime(Time time, unsigned char mode)
{
	switch (mode)
	{
	case 0:
		cout << time.hour << ':' << time.minute;
		return;
	case 1:
		cout << time.hour * 60 + time.minute << " minutes";
		return;
	case 2:
		cout << time.hour << "h and " << time.minute << "min";
		return;
	default:
		return;
	}
}

Time subtractTime(Time start, Time end)
{
	int startMinutes = start.hour * 60 + start.minute;
	int endMinutes = end.hour * 60 + end.minute;

	int totalMinutes = endMinutes - startMinutes;
	int hours = totalMinutes / 60;
	int minutes = totalMinutes % 60;

	Time time = { (unsigned short)hours, (unsigned short)minutes };

	return time;
}