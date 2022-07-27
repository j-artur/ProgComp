#include <iostream>
using namespace std;

int main()
{
	float factoryCost, finalCost;
	float taxes = .45;
	float distributorFee = .28;

	cout << "Factory cost: (R$) ";
	cin >> factoryCost;

	float taxesCost = factoryCost * taxes;
	float distributorCost = factoryCost * distributorFee;

	finalCost = factoryCost + taxesCost + distributorCost;

	cout << "The cost to the consumer is R$" << finalCost << endl;
}