#include <iostream>
#include <iomanip>
#include "q3.h"

Event newEvent();

int main() {
	using namespace std;

	Event events[10] = { 0 };

	cout << "Insert 2 events:\n";
	for (size_t i = 0; i < 2; i++)
	{
		cout << '#' << i + 1 << '\n';
		events[i] = newEvent();
	}

	cout << "--------------------\n";

	cout << "Registered Events\n";
	for (size_t i = 0; i < 2; i++)
	{
		cout << setfill('0') << setw(2) << events[i].date.day << '/' <<
			setfill('0') << setw(2) << events[i].date.month << '/' <<
			setfill('0') << setw(2) << events[i].date.year << ' ';

		cout << setfill('0') << setw(2) << events[i].time.hour << ':' <<
			setfill('0') << setw(2) << events[i].time.min << ' ';

		cout << events[i].description << '\n';
	}
}

Event newEvent()
{
	using namespace std;

	Event event;

	Date date;
	cout << "Date: ";
	cin >> date.day;
	cin >> date.month;
	cin >> date.year;
	event.date = date;

	Time time;
	cout << "Time: ";
	cin >> time.hour;
	cin >> time.min;
	event.time = time;

	cout << "Description: ";
	cin.ignore(1);
	cin.getline(event.description, 17);

	return event;
}