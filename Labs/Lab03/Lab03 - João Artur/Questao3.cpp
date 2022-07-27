#include <iostream>
using namespace std;

int main()
{
	float weight;

	float METrun = 7.0, METbike = 7.0, METswim = 8.0;

	float time, energy = 0;
	int hours, minutes;

	cout << "Your weight in kilograms: ";
	cin >> weight;

	cout << "Time spent running: ";
	cin >> hours;
	cin.ignore();
	cin >> minutes;
	cin.ignore();

	time = minutes + (hours * 60);
	energy += METrun * weight * (time / 60);

	cout << "Time spent biking: ";
	cin >> hours;
	cin.ignore();
	cin >> minutes;
	cin.ignore();

	time = minutes + (hours * 60);
	energy += METbike * weight * (time / 60);

	cout << "Time spent swimming: ";
	cin >> hours;
	cin.ignore();
	cin >> minutes;
	cin.ignore();

	time = minutes + (hours * 60);
	energy += METswim * weight * (time / 60);

	cout << endl;
	cout << "You've burned a total of " << energy << " calories." << endl;
}