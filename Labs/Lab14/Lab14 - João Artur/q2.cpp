#include <iostream>
#include <iomanip>

using namespace std;

struct Time
{
	short hour;
	short minute;
};

void showTime(Time*);

int main()
{
	Time time;
	Time* ptr = &time;

	cout << "What time is it? ";
	cin >> time.hour;
	cin.ignore(1);
	cin >> time.minute;
	
	ptr->hour++;

	cout << "Your clock is late, the correct time is ";
	showTime(ptr);
	cout << ".\n";

	return 0;
}

void showTime(Time* ptr)
{
	cout << setw(2) << setfill('0') << ptr->hour << ':' << 
			setw(2) << setfill('0') << ptr->minute;
}