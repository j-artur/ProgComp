#include <iostream>
#include "division.h"

int main()
{
	using namespace std;

	int n1, n2;
	cout << "Type two integer numbers: ";
	cin >> n1;
	cin >> n2;

	cout << "The quotient of " << n1 << '/' << n2 << " is " << quotient(n1, n2) << '\n';
	cout << "The remainder of the division " << n1 << '%' << n2 << " is " << remaind(n1, n2) << '\n';
}
