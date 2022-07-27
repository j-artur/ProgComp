#include <iostream>
#include <string>
#include "q5.h"

using namespace std;

int main()
{
	Event event;

	cout << "New event.\n";
	cout << "Name: ";
	getline(cin, event.name);
	cout << "Place: ";
	getline(cin, event.place);
	event.date = newDate();
	event.time = newTime();

	cout << event.name << " at " << event.place << " at " << event.date.day << '/' << event.date.month << '/' << event.date.year << " at " << event.time.hour << ':' << event.time.minute << '.';

	return 0;
}
