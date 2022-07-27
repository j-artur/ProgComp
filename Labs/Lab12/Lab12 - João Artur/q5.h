#include <iostream>
#include <string>

struct Date
{
	unsigned short day = 1;
	unsigned short month = 1;
	unsigned short year = 1;
};

struct Time
{
	unsigned short hour = 0;
	unsigned short minute = 0;
	unsigned short second = 0;
};

struct Event
{
	std::string name;
	Date date;
	Time time;
	std::string place;
};

Date newDate();
Time newTime();