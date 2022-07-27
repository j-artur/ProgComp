#include <iostream>
#include <string>
#include "q5.h"

using namespace std;

Date newDate()
{
	Date date;

	cout << "Date (dd/mm/yyyy): ";
	cin >> date.day;
	cin.ignore(1);
	cin >> date.month;
	cin.ignore(1);
	cin >> date.year;

	return date;
}

Time newTime()
{
	Time time;

	cout << "Time (hh:mm): ";
	cin >> time.hour;
	cin.ignore(1);
	cin >> time.minute;

	return time;
}
