#include <iostream>
#include "division.h"

int main()
{
	using namespace std;

	const short mInKm = 1000;

	int meters;
	cout << "Enter a distance in meters: ";
	cin >> meters;

	cout << meters << " meters is equivalent to " << quotient(meters, mInKm) << " kilometers and " << remaind(meters, mInKm) << " meters.";
}