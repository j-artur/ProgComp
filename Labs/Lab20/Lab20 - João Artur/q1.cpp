#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	unsigned distance;
	cout << "What's the distance in kilometers? ";
	cin >> distance;

	unsigned pricePerKm = 30;
	if (distance <= 200) pricePerKm = 50;
	else if (distance <= 400) pricePerKm = 40;

	float ticketPrice = distance * pricePerKm / 100;

	cout.imbue(locale(""));
	cout << "The ticket will cost R$" << setprecision(2) << fixed << ticketPrice << ".\n";

	return 0;
}