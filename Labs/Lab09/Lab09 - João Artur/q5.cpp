#include <iostream>

int main()
{
	double var1 = 245.795;
	int var2 = int (var1);

	var1 *= 100;
	var2 *= 100;

	std::cout << "var1: " << var1 << '\n';
	std::cout << "var2: " << var2 << '\n';
}