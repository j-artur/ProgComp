#include <iostream>
using namespace std;

int main()
{
	int hours, minutes;
	char colon;

	cout << "What time is it? ";
	cin >> hours;
	cin >> colon;
	cin >> minutes;

	cout << "Your watch is running late." << endl;
	cout << "It is now " << hours + 1 << colon << minutes << '.' << endl;
}