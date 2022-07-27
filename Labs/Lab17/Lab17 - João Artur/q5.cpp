#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int sum = 0;
	int squaredSum = 0;
	for (size_t i = 1; i <= 100; i++)
	{
		squaredSum += pow(i, 2);
		sum += i;
	}
	int sumSquared = pow(sum, 2);

	cout << "Squared sum: " << squaredSum << '\n';
	cout << "Sum squared: " << sumSquared << '\n';
	cout << "The difference is: " << sumSquared << " - " << squaredSum << " = " << sumSquared - squaredSum << '\n';

	return 0;
}

