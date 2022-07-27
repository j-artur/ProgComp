#include <iostream>
#include <cmath>
using namespace std;

#define hourToMin 60

int receiveTime(string);
int travelTime(int, int);

int main()
{
	int departure = receiveTime("Type the departure time (HH:MM): ");
	int arrival = receiveTime("Type the arrival time (HH:MM): ");

	int hours, minutes;
	int time = travelTime(departure, arrival);
	hours = floor(time / 60);
	minutes = (time % 60);

	cout << "\nThe total time of travel was " << hours << " hours and " << minutes << " minutes.\n";
}

int receiveTime(string message)
{
	int hour, min;

	cout << message;
	cin >> hour;
	cin.ignore();
	cin >> min;

	return hour * hourToMin + min;
}

int travelTime(int departure, int arrival)
{
	return arrival - departure;
}