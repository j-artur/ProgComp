#include <iostream>
using namespace std;

float raisedWage(float);

int main()
{
	cout << "Current wage: R$";
	float wage;
	cin >> wage;

	cout << "Wage raised for R$" << raisedWage(wage);
}

float raisedWage(float wage)
{
	float raise = wage * 15 / 100;

	return wage + raise;
}