#include <iostream>
#include <iomanip>
using namespace std;

#define breadPrice .30
#define pastelPrice .25

double buy(string, double);

int main()
{
	cout << "Breads&Co.\n\n";

	double breads = buy("How many bread? ", breadPrice);
	double pastels = buy("How many pastels? ", pastelPrice);

	cout << fixed << setprecision(2);
	cout << "\nTotal purchases are $" << breads + pastels;
}

double buy(string msg, double price)
{
	short qty;

	cout << msg;
	cin >> qty;

	return qty * price;
}